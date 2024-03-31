
#include "/Users/edu/Documents/ESCOM/5 SEM/Teoria de Computacion/Programas/Definicion/Alfabeto/Alfabeto.cpp"
#include "/Users/edu/Documents/ESCOM/5 SEM/Teoria de Computacion/Programas/Definicion/Estados/Estados.cpp"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <string>

class NFA
{
    private:
        //Alfabeto del Automata
        Alfabeto sigma;
        //Set de estados que tendra el automata
        set<State> setDeEstados;

        //Estado aceptado inicial
        State estadoInicial;

        //Estados aceptados finales 
        set<State> setDeEstadosFinales;

        //Metodo para encontrar un estado
        State getEstado(int ID);
        //Metodo de limpia del NFA
        void clear(void);

    public:
        //Constructor por defecto
        NFA(void);
        //Costructor que define un NFA con estados y un alfabeto predeterminado
        NFA(Alfabeto al, set<State> stados, State incial, set<State> finales);
        //Constructor que define un NFA desde una copia de otro NFA
        NFA(NFA& rhsNFA);
        //Metodo que busca todos los caminos posibles utilizando deepSearch
        void deepSearch( std::string cadena, int idActual, vector<string>& caminos, int& caminoActual, const std::string& deadEnds, const std::string& winingPaths, vector<int>& pathStack);
        //Metodo que escribe en un archivo especificado los caminos encontrdos  
        void escribirPath(const std::string& archivo,const std::string& path );
        //Metodo que checa si el estado es aceptable
        bool aceptabe(const State& stdo);
        //Metodo que busca los caminos aceptables
        void depthSearch(std::string cadena, int idActual, std::string caminoActual, const std::string& deadEnds, const std::string& winingPaths, set<State>& Visitados);

        void borrarPathID(vector<int>& pathStack, int ID);
        ~NFA();



};