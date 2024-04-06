#include "./NFA/Inizializador.cpp"
#include "Tablero.cpp"
#include <iostream>
#include <limits>

using namespace std;

//Menu Generador de Movimientos
void menu(){
    int seleccion=0;
    string cad1, cad2;
    system("clear");
    cout<<"--------Hacerlo de forma aleatoria o de forma manual?--------"<<endl;
    cout<<"--------1) Aleatorio"<<endl;
    cout<<"--------2) Manual"<<endl;
    cout<<"--------3) Salir"<<endl<<"->";
    cin>>seleccion;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    static default_random_engine generador(time(NULL));
    uniform_int_distribution<int> n(4,10);
    int lim = n(generador);

    
    switch (seleccion)
    {
        //Aleatoria 
        case 1:
        system("clear");
            //Para el rojo
            cad1 = selectorAleatorioLim(lim).cadenaRojoNegro;
            cout<<"Cadena 1: "<<cad1<<endl;
            //Para el negro 
            cad2 = selectorAleatorioLim(lim).cadenaRojoNegro;
            if (cad1==cad2)
                cad2 = selectorAleatorioLim(lim).cadenaRojoNegro;
            cout<<"Cadena 2: "<<cad2<<endl;
            //Checamos el ultimo valor para que sea correcot
            if (cad1.back()!='r'){
                cad1.back()='r';
                cout<<"Se agrego una r al final para que sirva el automata"<<endl<<cad1<<endl;
            }
            if (cad2.back()!='b'){
                cad2.back()='b';
                cout<<"Se agrego una b al final para que sirva el automata"<<endl<<cad2<<endl;
            }

            inizializador(cad1,cad2);
            break;
            //Manual
        case 2:
            int seleccion2;
            cout<<"-------Generar los movimiento aleatoriamente o generarlos manualmente?"<<endl;
            cout<<"-------1)Aleatorios"<<endl;
            cout<<"-------2)Manual"<<endl<<"->";
            cin>>seleccion2;
            //Para ignorar el \n y que no salte las llamadas del getline
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (seleccion2==1){
                cout<<"Generando movimientos: "<<endl;
                //Para el rojo
                int lim = n(generador);
                cad1 = selectorAleatorioLim(lim).cadenaRojoNegro;
                cout<<"Cadena 1: "<<cad1<<endl;
                //Para el negro 
                cad2 = selectorAleatorioLim(lim).cadenaRojoNegro;
                if (cad1==cad2)
                    cad2 = selectorAleatorioLim(lim).cadenaRojoNegro;
                cout<<"Cadena 2: "<<cad2<<endl;
                //Checamos el ultimo valor para que sea correcot
                if (cad1.back()!='r'){
                    cad1.back()='r';
                    cout<<"Se agrego una r al final para que sirva el automata"<<endl<<cad1<<endl;
                }
                if (cad2.back()!='b')
                {
                    cad2.back()='b';
                    cout<<"Se agrego una b al final para que sirva el automata"<<endl<<cad2<<endl;
                }
            }
            //Fin de generacion
            else{
                cout<<"Escribe los movimientos \"r\" y \"b\" de la cadena 1"<<endl; 
                getline(cin,cad1);
                cout<<"Escribe los movimientos \"r\" y \"b\" de la cadena 2"<<endl; 
                getline(cin,cad2);
                if (cad1.back()!='r'){
                    cad1.back()='r';
                    cout<<"Se agrego una r al final para que sirva el automata"<<endl<<cad1<<endl;
                }
                if (cad2.back()!='b'){
                    cad2.back()='b';
                    cout<<"Se agrego una b al final para que sirva el automata"<<endl<<cad2<<endl;
                }
            }
            inizializador(cad1,cad2);
            break;
        default:
            break;
    }
    
}


int main(){

    int opc;
    system("clear");
    cout<<"-----1)Generar nuevos movimientos?"<<endl;
    cout<<"-----2)Utilizar movimientos ya generados"<<endl<<"->";
    int sel;
    do
    {
        cin>>sel;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if (sel==1)
            menu();

        cout<<"Repetir?\n1)SI\n2)NO";
        cin>>opc;
    } while (opc!=2);
    
     
    return 0;
}