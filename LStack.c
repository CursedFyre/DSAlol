#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//stack structure declaration
struct Stack {
    int arr[MAX_SIZE];
    int top;
};


//CHECKING FUNCTIONS
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}


int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}





//PUSH
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow%d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d Pushed\n", value);
}



//POP
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    }
    return stack->arr[stack->top--];
}



//DISP
int disp(struct Stack *stack){
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    else{
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
    }
}


int main() {
    struct Stack s;
    //initializing
    s.top=-1;
    int ch;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    while(1){
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch){

        case 1:
        int v;
        printf("\nEnter value to be pushed:");
        scanf("%d",&v);
        push(&s,v);
        break;
        
        case 2:
        printf("Popped element is: %d",pop(&s));
        break;
        
        case 3:
        disp(&s);
        break;
        
        case 4:
        exit(0);
        
        default:
        printf("Enter valid choice");
        
    }
    }

    return 0;
}