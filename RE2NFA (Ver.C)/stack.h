//Stack structure and function definitions for RE to NFA converter
#include<stdbool.h>

//Stack array structure
typedef struct Stack{
    int arr[1024];
    int top;
};

//function prototypes
void init(struct Stack *stack);
bool isEmpty(struct Stack *stack);
bool isFull(struct Stack *stack);
void push(struct Stack *stack, struct NFA *nfa);
int pop(struct Stack *stack);
int peek(struct Stack *stack);