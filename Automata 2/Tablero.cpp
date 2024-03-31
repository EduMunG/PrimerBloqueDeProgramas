#include <vector>
#include <string>
#include <random>
#include <map>
#include <ctime>


using namespace std;

//Estructura de la cadena
struct Cadena{
    vector<int> cadenaBinaria;
    string cadenaRojoNegro;

    Cadena(){
        cadenaBinaria.clear();
        cadenaRojoNegro= "";
    }
};
//Generador de la cadena aleatoria
Cadena selectorAleatorio(){
    Cadena cad; 
    int num;
    default_random_engine generador(time(NULL));
    uniform_int_distribution<int> distribucion(0,1);
    uniform_int_distribution<int> n(1,4);
    for (int i = 0; i < n(generador); i++){
        num = distribucion(generador);
        cad.cadenaBinaria.insert(cad.cadenaBinaria.begin()+i,num);
        if(num)
            cad.cadenaRojoNegro+="r";
        else
            cad.cadenaRojoNegro+="b";
    }
    return cad;
}
