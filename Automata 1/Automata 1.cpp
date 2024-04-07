#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

//Esta funcion hace las permutaciones
void Permutaciones(int n, std::string& alphabeto, std::string actual, std::string& potencia){
    if (n==0)
    {
        potencia+= ", "+ actual;
        return; 
    }    
    for (char c : alphabeto)
            Permutaciones(n - 1, alphabeto, actual + c, potencia);
    
}

//Esta funcion es equivalente a Sigma^n
void Pot(int n, std::string& alphabeto, std::string actual, std::string& potencia)
{   int i=1;
    for(;i<=n;i++){
        Permutaciones(i, alphabeto, actual, potencia);
    }
}

std::ostream& operator<<(std::ostream& os,const std::vector<int> frec){
    os<<"[";
    for (int i = 0; i <frec.size(); i++){
        os<<frec[i];
        if (i<frec.size()-1)
        {
            os<<", ";
        }
        
    }
    
    os<<"]";
    return os;
}


using namespace std;
int automata1(int n){
    std::string potencia;
    std::string alphabeto = "ab";
    int suma=0;
    for (int i = 1; i <= n; i++)
        suma+=pow(2,i);
    std::vector<int> freca(suma,0);
    std::vector<int> frecb(suma,0);
    //Agrega el inicio y el final de la potencia
    int a=-1; int b=0;
    potencia ="{e";
    Pot(n,alphabeto,"",potencia);
    potencia += "}";
    
    ofstream outFile("output.txt");
    if (outFile)
    {
        outFile <<"\n" << potencia;
        outFile.close();
        cout<<"\nEl archivo se a escrito con exito\n";
    }
    else
        cout<<"\nEl archivo no pudo ser creado\n";
    
    for (char c: potencia){
        if (c!=' '&&c!='{'&&c!='e')
        {
            if (c==',')
                a++;
            else if(c=='a')
                freca[a]++;
            else if(c=='b')
                frecb[a]++;
        }
    }
    ofstream File("Frecuencia.txt");
    if (File)
    {
        File<<"\nFrecuencia a: "<<freca<<"\nFrecuencia b: "<<frecb;
        File.close();
        cout<<"\nEl archivo se a escrito con exito\n";
    }
    else
        cout<<"\nEl archivo no pudo ser creado\n";

    system("python3.11 Automata\\ 1/Grafica1.py");
    return 0;
}