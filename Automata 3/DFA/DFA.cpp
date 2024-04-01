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

bool DFA::esEstadosDePrecedencia(State estadoActual, char letrapasada,const std::vector<State> visitados){
    if (visitados.empty()) return false; // Si no hay estados visitados, no puede haber precedencia

    const State& ultimoVisitado = visitados.back(); // Accede al último estado visitado
    set<int> sigID = ultimoVisitado.getNextStateID(letrapasada);
    return estadoActual.identifier == *sigID.begin();
    /* set<int> sigID = estado.getNextStateID(letra);
    return sigID.find(estadoPrevio) != sigID.end(); */
    /* set<int> sigID = estadoActual.getNextStateID(letra);
    // Verificar si el estado previo tiene una transición válida con el símbolo actual
    return sigID.find(estadoPrevio) != sigID.end(); */
}

void DFA::escribirPath(const std::string& archivo,const std::string& path){
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
        //cout<<parrafo;
        path="";
        idActual=estadoInicial.identifier;
        checarParrafo(parrafo, archivo,path,idActual,parra,palabra);
        parra++;
        palabra=0;
    }
}

void DFA::checarParrafo(const std::string parrafo, const string archivo, std::string& path, int& idActual, int& parra, int& palabra) {
    std::vector<State> visitados;
    char pasada;
    for (char letra : parrafo) {
        if(letra != ' '){
            if (sigma.simboloEnAlfabeto(letra)){
                if (getEstado(idActual) == estadoInicial) {
                    visitados.push_back(getEstado(idActual));
                    set<int> sigID = getEstado(idActual).getNextStateID(letra);
                    idActual = *sigID.begin();
                    pasada = letra;
                    path += letra;
                } else {
                    if (aceptabe(getEstado(idActual))) {
                        path += letra;
                        // Guarda al avanzar
                    }
                    
                    if (esEstadosDePrecedencia(getEstado(idActual), pasada, visitados)) {
                        visitados.push_back(getEstado(idActual));
                        set<int> sigID = getEstado(idActual).getNextStateID(letra);
                        idActual = *sigID.begin();
                        pasada = letra;
                        path += letra;
                    }
                }
            }
        } else {
            if (!path.empty()&&aceptabe(getEstado(idActual))) { // Asegurarse de que no se guarde una "palabra" vacía.
                escribirPath(archivo, "Palabra: " + path + ", Párrafo: " + std::to_string(parra) + ", Palabra #: " + std::to_string(palabra));
                palabra++;
            }
            path = "";
            idActual = estadoInicial.identifier;
            visitados.clear();
        }
    }
    // Verificar si la última palabra del párrafo se procesó correctamente
    if (!path.empty()&&aceptabe(getEstado(idActual))) {
        escribirPath(archivo, "Palabra: " + path + ", Párrafo: " + std::to_string(parra) + ", Palabra #: " + std::to_string(palabra));
        palabra++;
    }
}
