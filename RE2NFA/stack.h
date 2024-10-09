#include<stdbool.h>

//Stack array structure
typedef struct Stack{
	struct NFA *arr[1024];
	int top;
}Stack;

// Function prototypes
void init(struct Stack *stack);
bool isEmpty(struct Stack *stack);
bool isFull(struct Stack *stack);
void push(struct Stack *stack, struct NFA *nfa);
struct NFA *pop(struct Stack *stack);
struct NFA *peek(struct Stack *stack);
