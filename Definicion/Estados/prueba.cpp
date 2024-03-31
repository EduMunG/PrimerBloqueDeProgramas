#include "./Estados.cpp"






int main(int argc, char const *argv[])
{
    State estado;


    estado.setNextState(2,'c');
    estado.setNextState(3,'a');
    estado.setNextState(4,'d');
    estado.setNextState(4,'a');
    estado.setNextState(4,'f');
    estado.setNextState(4,'s');
    estado.setNextState(4,'v');
    estado.setNextState(5,'d');
    set<int> sta= estado.getNextStateID('d');
    State otro = *new State(estado);
    for (auto& i: sta){
        cout<<i<<" ";
    }
    

    cout<<endl<<estado<<endl<<otro<<endl;

    return 0;
}
