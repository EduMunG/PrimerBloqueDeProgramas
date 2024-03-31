#include "./Transiciones.hpp"

Transiciones:: Transiciones():
    simbolo(),
    idSigEstado(){}

Transiciones:: Transiciones (int siguienteEstado, char simboloUsuario):
    simbolo(simboloUsuario),
    idSigEstado(siguienteEstado){}

Transiciones:: ~Transiciones (void){
    simbolo='0';
    idSigEstado=-1;
}
Transiciones:: Transiciones (const Transiciones& nuevasTransiciones){
    simbolo = nuevasTransiciones.simbolo;
    idSigEstado= nuevasTransiciones.idSigEstado;
}

void Transiciones:: operator= (const Transiciones& rhs){
    this->simbolo=rhs.simbolo;
    this->idSigEstado=rhs.idSigEstado;
}

bool Transiciones:: operator== (const Transiciones& rhs) const{
    if ((this->simbolo==rhs.simbolo)&&(this->idSigEstado==rhs.idSigEstado)) return true;
    return false; 
}
bool Transiciones:: operator< (const Transiciones& rhs) const{
    if ((this->simbolo<=rhs.simbolo)) return true;
    return false; 
}