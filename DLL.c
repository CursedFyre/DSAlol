#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

// INSERT FUNCTIONS

void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value\n");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    if (head != NULL)
    {
        head->prev = ptr;
    }
    head = ptr;
    printf("\nInserted");
}

void endinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value\n");
    scanf("%d", &item);
    ptr->data = item;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        printf("\nInserted");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        ptr->prev = temp;
        printf("\nInserted");
    }
}

// DELETE FUNCTIONS

void begdel()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(ptr);
        printf("\nDeleted\n");
    }
}

void endel()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nList Empty");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nDeleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted\n");
    }
}

// TRAVERSE/DISPLAY

void disp()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("MT");
    }
    else
    {
        printf("\nElements are:\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

// TO SEARCH A VALUE

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("MT");
    }
    else
    {
        printf("\nEnter Value\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Not found\n");
        }
    }
}

void prev()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("MT");
    }
    else
    {
        printf("\nEnter Value\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("The location is %d ", i);
                if (ptr->prev != NULL)
                {
                    printf("Value held is %d", ptr->prev->data);
                }
                else
                {
                    printf("No previous node");
                }
                break;
            }
            i++;
            ptr = ptr->next;
        }
    }
}

int main()
{
    int ch = 0;
    printf("\n1.Insert in beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Search\n6.Display\n7.Previous value, position\n8.Exit\n");
    while (ch != 8)
    {
        printf("\nEnter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            beginsert();
            break;
        case 2:
            endinsert();
            break;
        case 3:
            begdel();
            break;
        case 4:
            endel();
            break;
        case 5:
            search();
            break;
        case 6:
            disp();
            break;
        case 7:
            prev();
            break;
        case 8:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Enter valid choice");
        }
    }
    return 0;
}
