/* 

    EDUARDO MUÑOZ GONZÁLEZ 5BM2
    ESCOM 
    TEORIA DE LA COMPUTACION
    DEFINICION DE ESTADO
 */
#pragma once



//#include "../Transiciones/Transiciones.cpp"
#include "../Transiciones/Transiciones.hpp"
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>


using namespace std;
    
class State
{
    
    public:
        
        // Conjunto de transciones de dicho estado.
        set<Transiciones> transitions;
        
        // Variable que almacena el número del estado dentro del DFA.
        int identifier;
        
        // Constructor por defecto.
        State (void);
        
        // Cosntructor al que se le pasa el ID del estado.
        State (int stateID);
        
        // Constructor de copia.
        State (const State& newState);
        
        // Destructor de la clase.
        ~State (void);
        
        // Método que limpia el estado.
        void clear (void);
        
        // Método que establece la transición de un estado con el siguiente dependiendo de un símbolo.
        void  setNextState(int nextStateID, char symbol) ;
        
        // Método que devuelve el identificador del siguiente estado dado un símbolo.
        set<int> getNextStateID (char symbol) const;

        // Método que devuelve si tiene transiciones el estado.
        int numberOfTransitions (void) const;
        
        // Método que devuelve los estados de las eps-transiciones.
        vector<int> getEpsTransitions(void) const;
        
        // Método que devuelve si un símbolo es usado en alguna transición.
        bool symbolIsUsed (char symbol) const;
        
        // Sobrecarga del operador que permite escribir el estado en un flujo.
        friend ostream& operator<< (ostream& os, const State& rhsState);
        
        // Sobrecarga del operador =.
        State& operator= (const State& rhs);
        
        // Sobrecarga del operador ==.
        bool operator== (const State& rhs) const;
        //Sobrecvarga del operador !=
        bool operator!= (const State& rhs) const;
        // Sobrecarga del operador <.
        bool operator< (const State& rhs) const;

};