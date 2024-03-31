#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

//Esta funcion hace las permutaciones
void Permutaciones(int n, std::string& alphabeto, std::string actual, std::string& potencia, int& a, int& b){
    if (n==0)
    {
        potencia+= ", "+ actual;
        for (char c : actual)
        {
            (c=='a')? a++ : b++ ;
        }
        return; 
    }    
    for (char c : alphabeto)
            Permutaciones(n - 1, alphabeto, actual + c, potencia,a,b);
}

//Esta funcion es equivalente a Sigma^n
void Pot(int n, std::string& alphabeto, std::string actual, std::string& potencia, int& a , int& b)
{   int i=1;
    for(;i<=n;i++){
        Permutaciones(i, alphabeto, actual, potencia, a, b);
    }
}



using namespace std;
int main(){
    std::string potencia;
    std::string alphabeto = "ab";
    int n=1;
    cout<<"Escribe la potencia del abecedario, si no escribe nada, el programa decidira un numero entre 1 a 1000: ";
    cin>>n;
    if (n==1)
        n=3;
    if (n>=1000)
        n=1000;
    //Agrega el inicio y el final de la potencia
    int a=0; int b=0;
    potencia ="{ e ";
    Pot(n,alphabeto,"",potencia,a,b);
    potencia += " }";

    ofstream outFile("output.txt");
    if (outFile)
    {
        outFile <<"\n" << potencia;
        outFile.close();
        cout<<"\nEl archivo se a escrito con exito\n";
    }
    else
        cout<<"\nEl archivo no pudo ser creado\n";
    
    ofstream File("Frecuencia.txt");
    if (File)
    {
        File<<"\nFrecuencia a: "<<a<<"\nFrecuencia b: "<<b;
        File.close();
        cout<<"\nEl archivo se a escrito con exito\n";
    }
    else
        cout<<"\nEl archivo no pudo ser creado\n";
    
    return 0;
}