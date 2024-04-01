#include "Estados.hpp"
    
    State:: State (void):
    transitions(),
    identifier(-1){}
    
    State:: State (int stateID):
    transitions(),
    identifier(stateID){}
    
    State:: State (const State& newState)
    {
        transitions = newState.transitions;
        identifier = newState.identifier;
    }
    
    State:: ~State(void)
    {
        clear();
    }
    
    void State:: clear (void)
    {
        transitions.clear();
        identifier = -1;
    }
    
    void State:: setNextState (int idSiguienteEstado, char simbolo)  
    {
        
        Transiciones  newTransiciones(idSiguienteEstado, simbolo);
        
        transitions.insert(newTransiciones);
    }
  
  
    set<int> State:: getNextStateID (char simbolo) const
    {
        
        set<int> result;
        set<Transiciones>::iterator it = transitions.begin();
        
        for (;it!=transitions.end(); it++)
        {
            if ((*it).simbolo == simbolo) { result.insert((*it).idSigEstado);}
        }
        
        return result;
        
    }


    bool State:: hasEpsTransitions(void)
    {
        bool result = false;
        set<Transiciones>::iterator it = transitions.begin();
        
        while ((it!=transitions.end())&&!result)
        {
            if ((*it).simbolo == '&') { result = true; }
            else it++;
        }
        
        return result;
    }
    
    int State:: numberOfTransitions (void) const
    {
        return transitions.size();
    }
    
    vector<int> State:: getEpsTransitions(void) const
    {
        vector<int> result;
        set<Transiciones>::iterator it = transitions.begin();
        
        for (;it!=transitions.end(); it++)
        {
            if ((*it).simbolo == '&') { result.push_back((*it).idSigEstado);} //cout<< "dentro=" << (*it).idSiguienteEstado << endl;;}
        }
        
        return result;
    }
    
    bool State:: symbolIsUsed(char simbolo) const
    {
        
        bool found = false;
        set<Transiciones>::iterator it = transitions.begin();
        
        while ((it!=transitions.end())&&!found)
        {
            if ((*it).simbolo == simbolo) { found = true;}
            else it++;
        }
        
        return found;
    }
    
    ostream& operator<< (ostream& os, const State& rhsState)
    {
        os << rhsState.identifier;
        return os;
    }
    
    State& State:: operator= (const State& rhs)
    {
        this->transitions = rhs.transitions;
        this->identifier = rhs.identifier;
        
        return *this;
    }
        
    bool State:: operator== (const State& rhs) const
    {
        
        if ((this->identifier == rhs.identifier) && ((this->transitions).size() == rhs.transitions.size()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool State:: operator!=(const State& rhs) const
    {
        if ((this->identifier)!= rhs.identifier)
        {
            return true;
        }
        else{

            return false;
        }
        
    }
        
    bool State:: operator< (const State& rhs) const
    {
        if (this->identifier < rhs.identifier) return true;
        return false;
    }