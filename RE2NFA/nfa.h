//NFA struct definitions for RE to NFA converter
//NFA contains start state, accept state, and a pointer to a transition table
struct NFA
{
    int Start;
    int Accept;
    char *Transitions[1024];
};
//Transition contains first state, second state, and transition symbol
struct Transition
{
    int state1;
    int state2;
    char transSymbol;
};
