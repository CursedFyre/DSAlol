#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* create() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("UNDERFLOW\n");
        exit(1);
    } else {
        struct Node* temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        printf("Dequeued element: %d\n", data);
    }
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = create();
    int choice, value;
    printf("\nQueue Operations:\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    while (1){
	printf("\nEnter choice:");
        scanf("%d", &choice);
      
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(q,value);
                break;
            case 2:
                value = dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}