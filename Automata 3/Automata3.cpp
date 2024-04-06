#include <iostream>
#include <fstream>
#include <vector>
#include "./DFA/DFA.cpp"

using namespace std;

void inizializar(Alfabeto& sigma, set<State>& setDeEstados, set<State>& setDeEstadosFinales,State& estadoInicial, bool& falla);

int Automata3() {
    //Inicializacion de variables para abrir el texto
    string pdfPath = "Assets/Text/Feminazi.txt";
    string textContent;
    string line;
    ifstream infile(pdfPath);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            textContent += line + "\n";
        }

        cout << "Text content extracted from PDF document:" << endl;
    } else {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    // Ahora vamos a extraer párrafos
    vector<string> parrafos;
    string parrafo_actual = "";
    for (char c : textContent) {
        if (c == '\n') {
            if (!parrafo_actual.empty()) {
                parrafos.push_back(parrafo_actual);
                parrafo_actual = "";
            }
        } else {
            parrafo_actual += c;
        }
    }
    // Agregar el último párrafo si no se añadió
    if (!parrafo_actual.empty()) {
        parrafos.push_back(parrafo_actual);
    }
/*     for (string parra: parrafos)
    {
        cout<<parra;
    }
 */

    bool falla;
    Alfabeto sigma;
    set<State> setDeEstados;
    State estadoInicial;
    set<State> setDeEstadosFinales;
    //Inizializador de estaods 
    inizializar(sigma,setDeEstados,setDeEstadosFinales,estadoInicial, falla);
    //cout<<sigma<<endl<<estadoInicial<<endl;
    //set<State>::iterator it=setDeEstadosFinales.begin();
/*     for (;it!=setDeEstadosFinales.end();it++)
        cout<<endl<<(*it);
     */
    //Inicializador de DFA
    cout<<"A0";
    DFA DEefeA(sigma,setDeEstados,estadoInicial,setDeEstadosFinales);

    //Inizialzador de varias bariables
    int idActual =estadoInicial.identifier;
    int parra, palabra;
    parra=palabra=0;
    cout<<idActual<<parra<<palabra;
    string paths="";
    string out="infopalabras.txt";

    //Llamada a funcion
    DEefeA.detPalabra(parrafos,out,paths,idActual,parra,palabra);
    return 0;
}

void inizializar(Alfabeto& sigma, set<State>& setDeEstados, set<State>& setDeEstadosFinales,State& estadoInicial, bool& falla){
    string alfa="feminazltovjr";
    //Poniendo el alfabeto
    sigma =*new Alfabeto(alfa, falla);
    //Iniciando los estados y sus transiciones
    State q1(1);  q1.setNextState(12,'f'); q1.setNextState(111,'t'); q1.setNextState(116,'v');
    State q12(12); q12.setNextState(13,'e');
    State q13(13); q13.setNextState(14,'m');
    State q14(14); q14.setNextState(15,'i');
    State q15(15); q15.setNextState(16,'n');
    State q16(16); q16.setNextState(17,'a');
    State q17(17); q17.setNextState(18,'z'); q17.setNextState(110,'l');
    State q18(18); q18.setNextState(19,'i');
    State qf19(19); //final
    State qf110(110); //final
    State q111(111); q111.setNextState(112,'o');
    State q112(112); q112.setNextState(113,'n'); q112.setNextState(119,'r');
    State q113(113); q113.setNextState(114,'t');
    State q114(114); q114.setNextState(115,'a');
    State q116(116); q116.setNextState(117,'i');
    State q117(117); q117.setNextState(118,'e');
    State q118(118); q118.setNextState(114,'j');
    State q119(119); q119.setNextState(114,'t');
    State qf115(115); //final

    //Anadiendo 
    setDeEstados.insert(q1);
    setDeEstados.insert(q12);
    setDeEstados.insert(q13);
    setDeEstados.insert(q14);
    setDeEstados.insert(q15);
    setDeEstados.insert(q16);
    setDeEstados.insert(q17);
    setDeEstados.insert(q18);
    setDeEstados.insert(qf19); //final
    setDeEstados.insert(qf110);//final
    setDeEstados.insert(q111); 
    setDeEstados.insert(q112); 
    setDeEstados.insert(q113); 
    setDeEstados.insert(q114); 
    setDeEstados.insert(q116); 
    setDeEstados.insert(q117); 
    setDeEstados.insert(q118); 
    setDeEstados.insert(q119); 
    setDeEstados.insert(qf115); //final

    estadoInicial=q1;

    setDeEstadosFinales.insert(qf110);
    setDeEstadosFinales.insert(qf19);
    setDeEstadosFinales.insert(qf115);

}




