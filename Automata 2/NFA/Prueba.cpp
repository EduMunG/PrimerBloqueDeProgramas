#include "./NFA.cpp"
#include "string"

int main(int argc, char const *argv[])
{
    
    set<State> estados;
    //Definiendo los estados

    State q1(1);/*RED*/ q1.setNextState(2,'r'); q1.setNextState(6,'r'); /*Black*/q1.setNextState(5,'b');
    State q2(2);/*RED*/ q2.setNextState(6,'r'); /*BLACK*/ q2.setNextState(1,'b'); q2.setNextState(3,'b'); q2.setNextState(5,'b'); q2.setNextState(7,'b');
    State q3(3);/*RED*/ q3.setNextState(2,'r'); q3.setNextState(4,'r'); q3.setNextState(6,'r'); q3.setNextState(8,'r');/*BLACK*/ q3.setNextState(7,'b');
    State q4(4);/*RED*/ q4.setNextState(8,'r');/*BLACK*/q4.setNextState(3,'b'); q4.setNextState(7,'b');
    State q5(5);/*RED*/ q5.setNextState(2,'r'); q5.setNextState(6,'r'); q5.setNextState(10,'r'); /*BLACk*/q5.setNextState(1,'b'); q5.setNextState(9,'b');
    State q6(6);/*RED*/ q6.setNextState(2,'r'); q6.setNextState(10,'r'); /*BLACk*/ q6.setNextState(1,'b'); q6.setNextState(3,'b'); q6.setNextState(5,'b'); q6.setNextState(7,'b'); q6.setNextState(9,'b'); q6.setNextState(11,'b');
    State q7(7);/*RED*/ q7.setNextState(2,'r'); q7.setNextState(4,'r'); q7.setNextState(6,'r'); q7.setNextState(8,'r'); q7.setNextState(10,'r'); q7.setNextState(12,'r');/*BLACK*/ q7.setNextState(3,'b'); q7.setNextState(11,'b');
    State q8(8);/*RED*/ q8.setNextState(4,'r'); q8.setNextState(12,'r'); /*BLACK*/ q8.setNextState(3,'b'); q8.setNextState(7,'b'); q8.setNextState(11,'b');
    State q9(9);/*RED*/ q9.setNextState(6,'r'); q9.setNextState(10,'r'); q9.setNextState(14,'r'); /*BLACK*/ q9.setNextState(5,'b'); q9.setNextState(13,'b');
    State q10(10);/*RED*/ q10.setNextState(6,'r'); q10.setNextState(14,'r'); /*BLACK*/q10.setNextState(5,'b'); q10.setNextState(7,'b'); q10.setNextState(9,'b'); q10.setNextState(11,'b'); q10.setNextState(13,'b'); q10.setNextState(15,'b');
    State q11(11);/*RED*/ q11.setNextState(6,'r'); q11.setNextState(8,'r'); q11.setNextState(10,'r'); q11.setNextState(12,'r'); q11.setNextState(14,'r'); q11.setNextState(16,'r');/*BLACK*/ q11.setNextState(7,'b'); q11.setNextState(15,'b');
    State q12(12);/*RED*/ q12.setNextState(8,'r'); q12.setNextState(16,'r');/*BLACK*/ q12.setNextState(7,'b'); q12.setNextState(11,'b'); q12.setNextState(15,'b');
    State q13(13);/*RED*/ q13.setNextState(10,'r'); q13.setNextState(14,'r');/*BLACK*/ q13.setNextState(9,'b');
    State q14(14);/*RED*/ q14.setNextState(10,'r');/*BLACK*/ q14.setNextState(9,'b'); q14.setNextState(11,'b'); q14.setNextState(13,'b'); q14.setNextState(15,'b');
    State q15(15);/*RED*/ q15.setNextState(10,'r'); q15.setNextState(12,'r'); q15.setNextState(14,'r'); q15.setNextState(16,'r');/*BLACK*/ q15.setNextState(11,'b');
    State q16(16);/*RED*/ q16.setNextState(12,'r');/*BLACK*/ q16.setNextState(11,'b'); q16.setNextState(15,'b');

    set<State> final;
    //Anadiendo los estados
    final.insert(q16);
    estados.insert(q1);
    estados.insert(q2);
    estados.insert(q3);
    estados.insert(q4);
    estados.insert(q5);
    estados.insert(q6);
    estados.insert(q7);
    estados.insert(q8);
    estados.insert(q9);
    estados.insert(q10);
    estados.insert(q11);
    estados.insert(q12);
    estados.insert(q13);
    estados.insert(q14);
    estados.insert(q15);
    estados.insert(q16);
    bool falla;
    string alfa="rb";
    Alfabeto a(alfa, falla);
    NFA nfa= *new NFA(a,estados,q1,final);
    std::string movimientos = "rbrbr";
    std::string deadEnds="dead_ends.txt";
    std::string wining="winis.txt";
    std::vector<int> pathStack;
    std::string camino="";
    set<State> visitados;
    //Para evitar segmentation fault
    int caminoActual=1;
    nfa.depthSearch(movimientos,q1.identifier,camino,deadEnds,wining, visitados);
    //NFA2
    std::string movimientos2="brbrb";
    set<State> final2;
    final2.insert(q13);
    set<State> visitados2;
    NFA nfa2 = *new NFA(a,estados,q4,final2);
    nfa2.depthSearch(movimientos2,q4.identifier,camino,"dead_ends2.txt","Winis2.txt",visitados2);    
    return 0;
}
