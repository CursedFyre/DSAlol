#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Define a structure for the stack
struct Stack {
    int top;
    char items[MAX_LENGTH];
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push a character onto the stack
void push(struct Stack* stack, char c) {
    if (stack->top == MAX_LENGTH - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* input) {
    int length = strlen(input);
    struct Stack stack;
    initialize(&stack);

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < length; i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter a string: ");
    scanf("%s", input);

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}