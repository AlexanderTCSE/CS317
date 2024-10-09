//Alexander Tattersall
//CS317 - Professor Kabir
//Stack code for RE processor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

//Initialize an empty stack
void init(struct Stack *stack){
    stack -> top = -1;
}

//Check if stack is empty, return boolean T/F
bool isEmpty(struct Stack *stack){
    return stack->top == -1;
}

//Check if stack is full, return boolean T/F
bool isFull(struct Stack *stack){
    return stack->top == 1024-1;
}

//Push an NFA onto the stack
void push(struct Stack *stack, struct NFA *nfa){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    stack -> arr[++stack->top] = nfa;	//increment top and add pointer to NFA
}

//Pop the top element of the stack
struct NFA *pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack->arr[stack->top--];	//return top element and decrement
}

//Peek at the top element of the stack
struct NFA *peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Empty\n");
        return NULL;
    }
    return stack->arr[stack->top];
}
