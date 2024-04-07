/* 

    EDUARDO MUÑOZ GONZÁLEZ 5BM2
    ESCOM 
    TEORIA DE LA COMPUTACION
    DEFINICION DE ALFABETO
 */
#pragma once



#include <cstdio>
#include <set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Alfabeto
{
public:
    //Conjunto de alfabetos
    set<char> simbolos;
    //Constructores
    Alfabeto();
    //Constructor para pasar una serie de simbolos
    Alfabeto(string alfabeto, bool& fallaDeCreacion);

    //Constructor desde una copia de la clase
    Alfabeto(const Alfabeto& nuevoAlfabeto);

    //Metodo para devolver el numero de elementos en el alfabeto
    int tamano() const;

    //Metodos para instertar un elemento al alfabeto
    void insertar(char& simbolo);
    //Metodos que devuelve el simbolo que esta dentro de una posicion dada 
    char getSimbolo(int pos) const;
    // string getSimbolo(int pos) const;
    // int getSimbolo(int pos) const;
    //Metodo que determina si una cadena tiene o es un elemento del alfabeto
    bool estaCorrecto(string& lenguaje);

    //Metodo de limpieza
    void limpiar();

    //Sobrecarga para el elemto de insercion para poder imprimir el alfabeto en pantalla
    friend ostream& operator<< (ostream& os, const Alfabeto& rhs);

    //Sobrecarga para el elemento = que iguala dos alfabetos

    void operator= (const Alfabeto rhs); 

    bool simboloEnAlfabeto(char token) const;
private:
    //Metodos para crear el Alfabeto
    void crearAlfabeto(string alfabetoUsuario, bool& fallaDeCreacion);
    //Metodos que determina si un simbolo esta en el alfabeto 
    
    //Metoodo que checa si el simbolo es aceptable
    bool legal(char& token);
    
};
