//Alexander Tattersall
//CS317 - Professor Kabir
//Stack code for RE processor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

//Initialize an empty stack
void init(struct Stack *stack){
    stack -> top = NULL;
}

//Check if stack is empty, return boolean T/F
bool isEmpty(struct Stack *stack){
    return stack->top == NULL;
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
    stack -> arr[++stack->top] = nfa;
}

//Pop the top element of the stack
int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

//Peek at the top element of the stack
int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Empty\n");
        return NULL;
    }
    return stack->arr[stack->top];
}