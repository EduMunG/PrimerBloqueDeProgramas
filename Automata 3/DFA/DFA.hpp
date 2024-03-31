#include "../../Definicion/Alfabeto/Alfabeto.cpp"
#include "../../Definicion/Estados/Estados.cpp"
/* ATENCION!!! ACuerdate que nada mas copiaste la clase que hiciste del NFA. Borra metoods y cambia cosas */

class DFA
{
private:

    Alfabeto sigma;

    set<State> setDeEstados;
    State estadoInicial;
    set<State> setDeEstadosFinales;

    State getEstado(int ID);
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
    void escribirPath(const std::string& archivo,const std::string& path );
    //Metodo que checa si el estado es aceptable
    bool aceptabe(const State& stdo);
    //Metodo del automata determinista.
    void detPalabra(const std::vector<string> parrafos, const std::string archivo, std::string& path);
    
    void borrarPathID(std::vector<int>& pathStack, int ID);
    ~DFA();

};