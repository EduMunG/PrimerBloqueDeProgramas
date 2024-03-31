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

void DFA::escribirPath(const std::string& archivo,const std::string& path){
    std::ofstream outfile(archivo, std::ios::out);
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


void DFA::detPalabra(const std::vector<string>parrafos, const string archivo, std::string& path){
   
    int parra=0;
    int palabra=0;
    for (string parrafo:parrafos)
    {
        for (char letra: parrafo)
        {
            if (letra!=' ')
            {
                if (sigma.simboloEnAlfabeto(letra))
                {
                    path+=letra;
                    set<State>::iterator it=setDeEstados.begin();
                    for (;it!=setDeEstados.end();it++)
                    {
                        set<int> sigID= (*it).getNextStateID(letra);
                    }
                }
                else{
                    path="";
                }
            }
            else 
                palabra++;
        }
        parra++;
    }
    

}

