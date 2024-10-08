//Stack structure and function definitions for RE to NFA converter
//Necessary includes
#include<stdio.h>
#include<stdbool.h>

//Stack array structure
struct Stack{
    int arr[1024];
    int top;
};

//function prototypes
void init();
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, struct NFA *nfa);
int pop(Stack *stack);
int peek(Stack *stack);

//Initialize an empty stack
void init(){
    stack -> top = -1;
}

//Check if stack is empty, return boolean T/F
bool isEmpty(Stack *stack){
    return stack->top == -1;
}

//Check if stack is full, return boolean T/F
bool isFull(Stack *stack){
    return stack->top == 1024-1;
}

//Push an NFA onto the stack
void push(Stack *stack, struct NFA *nfa){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    stack -> arr[++stack->top] = value;
}

//Pop the top element of the stack
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return;
    }
    struct NFA popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

//Peek at the top element of the stack
int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}