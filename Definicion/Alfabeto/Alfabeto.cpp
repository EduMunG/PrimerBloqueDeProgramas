/* 

    EDUARDO MUÑOZ GONZÁLEZ 5BM2
    ESCOM 
    TEORIA DE LA COMPUTACION
    DEFINICION DE ALFABETO
 */


#include "./Alfabeto.hpp"

    Alfabeto::Alfabeto(): 
    simbolos(){}
    
    Alfabeto::Alfabeto(string alfabeto, bool& fallaDeCreacion){
        crearAlfabeto(alfabeto, fallaDeCreacion);
    }

    Alfabeto::Alfabeto(const Alfabeto& nuevoAlfabeto){
        simbolos = nuevoAlfabeto.simbolos;
    }
    
    void Alfabeto::insertar(char& simbolo){
        simbolos.insert(simbolo);
    }
    int Alfabeto:: tamano() const{
        return simbolos.size();
    }


    char Alfabeto:: getSimbolo(int pos) const{
       
        if(pos<tamano()){
            int i=0;
            char resultado;
            bool encontrado= false;
            //Iterador que recorre los simbolos. Es un puntero
            set<char>::iterator it = simbolos.begin();

            while((it!=simbolos.end())&& !encontrado){
                //Si llegamos a la posicion dada por el usuario
                if(pos == i) {
                    //Se guarda lo que haya en it al resultado y decimos que ya lo encontramos
                    resultado = *it; 
                    encontrado=true;
                }//Sino seguimos buscando
                else { it++; i++;}
            }
            return resultado;

        }else{
            return -1;
        }
    }


bool Alfabeto:: estaCorrecto(string& lenguaje){
    bool correcto= true;
    int i=0;
    while ((i<lenguaje.size())&&correcto){
        if (!simboloEnAlfabeto(lenguaje[i])) correcto=false;
        else i++;
    }
    return correcto;
}

void Alfabeto:: limpiar(){
    simbolos.clear();
}

ostream& operator<< (ostream& os, const Alfabeto& rhs){
    os<<"{ ";
    for (int i = 0; i < rhs.tamano(); i++)
        if (rhs.getSimbolo(i)!= '&')
        {
            os<<rhs.getSimbolo(i);
            if (i!=(rhs.tamano()-1)) os<<", ";
        }
    os<<" }";
    return os;
}

void Alfabeto:: operator= (const Alfabeto rhs){
    this->simbolos=rhs.simbolos;
}

//Metodos Privados


    bool Alfabeto:: simboloEnAlfabeto(char token) const{
        
        if (token == '&') return true;
        
        bool found = false; int i=0;
        while ((i<tamano())&&!found)
        {
            if (getSimbolo(i) == token) found = true;
            else i++;
        }
        
        return found;
        
    }
    
    void Alfabeto:: crearAlfabeto(string alfabetoUsuario, bool& fallaDeCreacion)
    {
        limpiar();
        
        fallaDeCreacion = false;
        int i = 0;
        
        while ((i<alfabetoUsuario.size())&&!fallaDeCreacion)
        {
            if (legal(alfabetoUsuario[i])) { simbolos.insert(alfabetoUsuario[i]); i++; }
            else fallaDeCreacion = true;
        }
    }
    
    bool Alfabeto:: legal (char& token)
    {
        return ((token!='~')&&(token!='&')&&(token!='{')&&(token!='}')&&(token!=' ')&&(token!=','));
    }



