#include "./Alfabeto.cpp"
#include <string>




int main(int argc, char const *argv[])
{
    std::string b="ab";
    bool falla;
    Alfabeto a(b, falla);
    cout<<a<<endl;
    char h='s';
    a.insertar(h);
    b="abs";
    cout<<a<<", tamano:"<<a.tamano()<<", simbolo en pos 2: "<<a.getSimbolo(2)<<", contiene abs?: "<<(a.estaCorrecto(b)? "Si":"No");
    a.limpiar();
    cout<<endl<<a;
    return 0;
}
