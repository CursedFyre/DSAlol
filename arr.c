
#include <stdio.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int size = 0;

void insert(int value, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    if (size >= MAX_SIZE) {
        printf("List is full, insertion not possible.\n");
        return;
    }

    for (int i = size - 1; i >= position; i--) {
        list[i + 1] = list[i];
    }

    list[position] = value;
    size++;

    printf("Element inserted successfully.\n");
    display();
}

void delete(int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    for (int i = position; i < size - 1; i++) {
        list[i] = list[i + 1];
    }

    size--;

    printf("Element deleted successfully.\n");
    display();
}

int search(int value) {
    for (int i = 0; i < size; i++) {
        if (list[i] == value) {
            return i;
        }
    }

    return -1;
    display();
}

void sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
    display();
}

void display() {
    printf("New list elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                insert(value, position);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                position = search(value);
                if (position != -1) {
                    printf("Value found at position %d.\n", position);
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 4:
                sort();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
                break;
            default:
                return -1;
        }
    }

    return 0;
}
