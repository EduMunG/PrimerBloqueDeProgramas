#include <vector>
#include <string>
#include <random>
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

//Generador aleatorio sin que el usuario haya dado un limite
Cadena selectorAleatorioLim(int lim){
    Cadena cad; 
    int num;
    static default_random_engine generador(time(NULL));
    //Generador de la cadena si es 0 es b y si es 1 es r 
    uniform_int_distribution<int> distribucion(0,1);
    uniform_int_distribution<int> n(4,100);
    for (int i = 0; i < lim; i++){
        num = distribucion(generador);
        //cad.cadenaBinaria.insert(cad.cadenaBinaria.begin()+i,num);
        cad.cadenaBinaria.push_back(num);
        if(num)
            cad.cadenaRojoNegro+="r";
        else
            cad.cadenaRojoNegro+="b";
    }
    return cad;
}
