/* 

    EDUARDO MUÑOZ GONZÁLEZ 5BM2
    ESCOM 
    TEORIA DE LA COMPUTACION
    DEFINICION DE TRANSICIONES
 */
#pragma once


#include <cstdio>
#include <iostream>
#include <set>


class Transiciones
{
public:
        // Atributo que especifica la transción para dicho símbolo.
        char simbolo;
        
        // Método que especifica el siguiente nodo de la transición.
        int idSigEstado;
        
        // Constructor por defecto de la clase.
        Transiciones (void);
        
        // Constructor al que se le pasa como parámetro el ID del siguiente estado, y el símbolo.
        Transiciones (int siguienteEstado, char simboloUsuario);
        
        // Constructor de copia al que se le pasa la nueva transiición.
        Transiciones (const Transiciones& nuevasTransiciones);
        
        // Destructor de la clase.
        ~Transiciones (void);
        
        // Sobrecarga del operador =.
        void operator= (const Transiciones& rhs);
        
        // Sobrecarga del operador ==.
        bool operator== (const Transiciones& rhs) const;
        
        // Sobrecarga del operador <.
        bool operator< (const Transiciones& rhs) const;
};
