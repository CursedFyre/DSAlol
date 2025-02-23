#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

//queue declaration, ont and rear initialization
int queue[MAX_SIZE];
int front = -1, rear = -1;


//ENQUEUE OR INSERT
void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("OVERFLOW");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d Equeued\n", value);
    }
}


//DEQUEUE OR DELETE
int dequeue() {
    int value;
    if (front == -1) {
        printf("UNDERFLOW");
        return -1;
    } else {
        value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }
}


//FULL AND EMPTY FUNC

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}


//DISPLAY

void disp() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("\nQueue Operations:\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    while (1){
	printf("\nEnter choice:");
        scanf("%d", &choice);
      
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

