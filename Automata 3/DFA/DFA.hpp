/* ATENCION!!! ACuerdate que nada mas copiaste la clase que hiciste del NFA. Borra metoods y cambia cosas 


    EDUARDO MUÑOZ GONZÁLEZ 5BM2
    ESCOM 
    TEORIA DE LA COMPUTACION
    DEFINICION DE UN DFA
 */

#include "../../Definicion/Alfabeto/Alfabeto.hpp"
#include "../../Definicion/Estados/Estados.hpp"
class DFA
{
private:

    Alfabeto sigma;

    set<State> setDeEstados;
    State estadoInicial;
    set<State> setDeEstadosFinales;

    State getEstado(int ID);
    
    //Metodo para encontrar el estado de precedenica
    bool esEstadosDePrecedencia(State estado, char letra,const std::vector<State> visitados);

    //Metodo de limpia del DFA
    void clear(void);

public:
        //Constructor por defecto
    DFA(void);
    //Costructor que define un DFA con estados y un alfabeto predeterminado
    DFA(Alfabeto al, set<State> stados, State incial, set<State> finales);
    //Constructor que define un DFA desde una copia de otro DFA
    DFA(DFA& rhsDFA);
    //Metodo que escribe en un archivo especificado los caminos encontrdos  
    void escribirPath(const std::string& archivo, const std::string& path );
    //Metodo que checa si el estado es aceptable
    bool aceptabe(const State& stdo);
    //Metodo del automata determinista.
    void detPalabra(const std::vector<string> parrafos, const std::string archivo, std::string& path, int& idActual, int& parra, int& palabra);
    //Metodo para checar parrafo
    void checarParrafo(const std::string parrafo, const string archivo, std::string& path, int& idActual, int& parra, int& palabra);
    
    void borrarPathID(std::vector<int>& pathStack, int ID);
    ~DFA();

};
