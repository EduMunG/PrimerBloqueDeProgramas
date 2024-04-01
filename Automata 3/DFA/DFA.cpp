#include "./DFA.hpp"
#include <fstream>

DFA::DFA():
    sigma(),
    setDeEstados(),
    setDeEstadosFinales(),
    estadoInicial(){}

DFA::DFA(Alfabeto al, set<State> stados, State inicial, set<State> finales){
    sigma = al;
    setDeEstados = stados;
    estadoInicial= inicial;
    setDeEstadosFinales=finales;
}

DFA::DFA( DFA& rhsDFA){
    sigma=rhsDFA.sigma;
    setDeEstados=rhsDFA.setDeEstados;
    setDeEstadosFinales=rhsDFA.setDeEstadosFinales;
    estadoInicial=rhsDFA.estadoInicial;
}

DFA::~DFA(){
    clear();
}

void DFA::clear(){
    sigma.limpiar();
    setDeEstados.clear();
    setDeEstadosFinales.clear();
    estadoInicial.clear();   
}

State DFA:: getEstado(int ID) {
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

bool DFA::esEstadosDePrecedencia(State estado, char letra){
    bool encontrado = false;
    set<State>::iterator it= setDeEstados.begin();
    set<int> sigID;
    while (((*it)!=estado)&&!encontrado)
    {
        sigID=(*it).getNextStateID(letra);
        for (int i : sigID)
        {
            if (i==estado.identifier)
            {
                encontrado =true;
            }
            else
                it++;
        }
    }
    return encontrado;
}

void DFA::escribirPath(const std::string& archivo,std::string& path){
    std::ofstream outfile(archivo, std::ios::app);
    if (outfile.is_open())
    {
        outfile.clear();
        outfile<<path<<std::endl;
        outfile.close();
    }
}

bool DFA:: aceptabe(const State& stdo){
    bool encontrado = false;
    set<State>::iterator it=setDeEstadosFinales.find(stdo);

    if (it==setDeEstadosFinales.end())
    {
        if ((*it)==stdo) return true;
        else return false;
    }
    else return true;

}

void DFA::borrarPathID(vector<int>& pathStack, int ID){
    vector<int>::iterator it=pathStack.begin();
    bool encontrado= false;
    while ((it!=pathStack.end())&&!encontrado)
    {
        if((*it)==ID) encontrado= true;
        else it++;
    }
    pathStack.erase(it);

}


void DFA::detPalabra(const std::vector<string>parrafos, const string archivo, std::string& path, int& idActual, int& parra, int& palabra){
   
    for (string parrafo:parrafos)
    {
        path="";
        idActual=estadoInicial.identifier;
        checarParrafo(parrafo, archivo,path,idActual,parra,palabra);
        parra++;
        palabra=0;
    }
}

void DFA::checarParrafo(const std::string parrafo, const string archivo, std::string& path, int& idActual, int& parra, int& palabra){ 
    for (char letra : parrafo) {
        if (letra != ' ') {
            if (sigma.simboloEnAlfabeto(letra)) {
                // Verificar si hay una transición válida desde el estado actual para la letra actual
                set<int> sigID = getEstado(idActual).getNextStateID(letra);
                if (!sigID.empty()) {
                    // Avanzar al siguiente estado
                    idActual = *sigID.begin();
                    // Anadir la letra al camino (palabra)
                    path += letra;
                    // Verificar si el estado actual es un estado final
                    if (aceptabe(getEstado(idActual))) {
                        string final="";
                        final+="Palabra encontrada: "+path + ", Palabra No. " + std::to_string(palabra) + ", Párrafo No. " + to_string(parra);
                        escribirPath(archivo,final);
                    }
                } else {
                    // Si no hay una transición válida, reiniciar el camino y el estado actual
                    path = "";
                    idActual = estadoInicial.identifier;
                }
            } else {
                // Si la letra no está en el alfabeto, reiniciar el camino y el estado actual
                path = "";
                idActual = estadoInicial.identifier;
            }
        } else {
            // Incrementar el contador de palabras si encontramos un espacio
            palabra++;
        }
    }
}

