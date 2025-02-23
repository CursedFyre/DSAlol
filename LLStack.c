#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return (root == NULL);
}

// Function to push an element onto the stack
void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value for an empty stack
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack without removing it
int peek(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value for an empty stack
    }
    return root->data;
}

// Function to print the elements of the stack
void printStack(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printStack(root);

    printf("Top element: %d\n", peek(root));

    printf("%d popped from the stack.\n", pop(&root));
    printf("Top element after pop: %d\n", peek(root));

    return 0;
}