#include "./NFA.hpp"

NFA::NFA():
    sigma(),
    setDeEstados(),
    setDeEstadosFinales(),
    estadoInicial(){}

NFA::NFA(Alfabeto al, set<State> stados, State inicial, set<State> finales){
    sigma = al;
    setDeEstados = stados;
    estadoInicial= inicial;
    setDeEstadosFinales=finales;
}

NFA::NFA( NFA& rhsNFA){
    sigma=rhsNFA.sigma;
    setDeEstados=rhsNFA.setDeEstados;
    setDeEstadosFinales=rhsNFA.setDeEstadosFinales;
    estadoInicial=rhsNFA.estadoInicial;
}

NFA::~NFA(){
    clear();
}

void NFA::clear(){
    sigma.limpiar();
    setDeEstados.clear();
    setDeEstadosFinales.clear();
    estadoInicial.clear();   
}

State NFA:: getEstado(int ID) {
    State temp;
    bool encontrado= false;
    set<State>::iterator it= setDeEstados.begin();
    while ((it!=setDeEstados.end())&&!encontrado)
    {
        if ((*it).identifier==ID)
        {
            encontrado= true;
            temp =*it;
        }
        else
            it++;
    }
    return temp;
}

void NFA::escribirPath(const std::string& archivo,const std::string& path){
    std::ofstream outfile(archivo, std::ios::app);
    if (outfile.is_open())
    {
        outfile.clear();
        outfile<<path<<std::endl;
        outfile.close();
    }
}

bool NFA:: aceptabe(const State& stdo){
    bool encontrado = false;
    set<State>::iterator it=setDeEstadosFinales.find(stdo);

    if (it==setDeEstadosFinales.end())
    {
        if ((*it)==stdo) return true;
        else return false;
    }
    else return true;

}

void NFA:: deepSearch(std::string cadena, int idActual, vector<string>& caminos, int& caminoActual, const std::string& deadEnds, const std::string& winingPaths, vector<int>& pathStack){
    //La cadena sera lo que de el usuario de rrbbrb o como sea 
    if (cadena.size()>=1)
    {
        //Cuardar el simbolo que hay en frente
        char simbolo=cadena.front();
        //Recortamos la cadena
        cadena=cadena.substr(1,cadena.size()-1);
        //Guardamos los sets de los estados, dado el simbolo que guardamos
        set<int> sigID = getEstado(idActual).getNextStateID(simbolo);
        if (sigID.size()>1)
        {
            //Hacemos variables temporales 
            string nuevoPath; int idTemp;
            for (int i = 0; i < sigID.size(); i++)
            {
                //Las inicializamos y las guardamos
                nuevoPath=""; caminos.push_back(nuevoPath);

                caminos.back()=caminos[caminoActual];
                nuevoPath.clear();
                idTemp=caminos.size()-1;
                pathStack.push_back(idTemp);
            }
        }
        //Si llegamos a un final
        if (sigID.empty())
        {
            caminos[caminoActual] +="q"+to_string(idActual)+" "+simbolo+" o|";
            cout<<caminos[caminoActual];
            escribirPath(deadEnds,caminos[caminoActual]);
            borrarPathID(pathStack,caminoActual);
            
        }
        else{
            set<int>::iterator it= sigID.begin();
            for (; it!=sigID.end(); it++)
            {                
                caminos[caminoActual]+="q"+to_string(idActual)+": "+simbolo+" q"+to_string(*it)+"| ";
                if ((*it)==16)
                {
                    escribirPath(winingPaths,caminos[caminoActual]);
                    borrarPathID(pathStack,caminoActual);
                }
                else{
                    escribirPath(deadEnds,caminos[caminoActual]);
                }
                //cout<<caminos[caminoActual];
                deepSearch(cadena,(*it),caminos,caminoActual,deadEnds,winingPaths,pathStack);
            }
        }   
    }
    else{
        caminos[caminoActual]+=to_string(idActual);
        borrarPathID(pathStack,caminoActual);
        if(!pathStack.empty()) caminoActual=pathStack.back();
    }
    
}

void NFA:: depthSearch(std::string cadena, int idActual, std::string caminoActual, const std::string& deadEnds, const std::string& winingPaths, set<State>& visitados){
    //Si ya visitamos el estado actual
    if((*visitados.find(getEstado(idActual))) == getEstado(idActual)){
        return;
    }
    visitados.insert(getEstado(idActual));
    
    if(cadena.empty()){
        if (aceptabe(getEstado(idActual)))
            escribirPath(winingPaths,caminoActual+" q"+std::to_string(idActual)+"|");
        else
            escribirPath(deadEnds,caminoActual+" q"+std::to_string(idActual)+"o|");
        visitados.erase(getEstado(idActual));
        return;
    } 
    char simbolo= cadena.front();
    //cout<<" Simbolo: "<<simbolo<<endl;
    caminoActual+="q"+std::to_string(idActual)+"<-'"+simbolo+"' ";
    //cout<<caminoActual<<endl;
    cadena=cadena.substr(1);
    //cout<<endl<<" Cadena: "<<cadena;
    set<int> sigID = getEstado(idActual).getNextStateID(simbolo);
    for (int it : sigID){
        //cout<<it<<endl;
        depthSearch(cadena,it,caminoActual,deadEnds,winingPaths, visitados);
    }
    visitados.erase(getEstado(idActual));
}


void NFA::borrarPathID(vector<int>& pathStack, int ID){
    vector<int>::iterator it=pathStack.begin();
    bool encontrado= false;
    while ((it!=pathStack.end())&&!encontrado)
    {
        if((*it)==ID) encontrado= true;
        else it++;
    }
    pathStack.erase(it);

}

