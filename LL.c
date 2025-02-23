#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;



//INSERT FUNCTIONS

void beginsert(){
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node));
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nInserted");
        disp();
}


void endinsert(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            printf("\nInserted");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nInserted");
        }
        disp();
}


void midinsert(){
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter location: ");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc-1;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nCan't insert\n");
                return;
            }

        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nInserted");
    }
    disp();
}


//DELETE FUNCTIONS

void begdel(){

    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nDeleted\n");
    }

    disp();
}


void endel(){

    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nList Empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nDeleted\n");
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted\n");
    }
    disp();
}


void midel(){

    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter location\n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc-1;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted");
    disp();
}


//TRAVERSE/DISPLAY


void disp(){
    struct node *ptr;
        ptr = head;
        if(ptr == NULL)
        {
            printf("MT");
        }
        else
        {
            printf("\nElements are:\n");
            while (ptr!=NULL)
            {
                printf("\n%d",ptr->data);
                ptr = ptr -> next;
            }
        }
}


//TO SEARCH A VALUE

void search(){

    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("MT");
   
    }
    else
    {
        printf("\nEnter Value\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("Not found\n");
        }
    }
}


void main()
{
    int ch =0;
    printf("\n1.Insert in beginning\n2.Insert at end\n3.Insert at specified location\n4.Delete from beginning\n5.Delete from end\n6.Delete node at specified location\n7.Search\n8.Display\n9.Exit\n");
    while(ch != 9)
    {
        printf("\nEnter choice\n");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:
            beginsert();
            break;
            case 2:
            endinsert();
            break;
            case 3:
            midinsert();
            break;
            case 4:
            begdel();
            break;
            case 5:
            endel();
            break;
            case 6:
            midel();
            break;
            case 7:
            search();
            break;
            case 8:
            disp();
            break;
            case 9:
            exit(0);
            printf("Exiting...");
            break;
            default:
            printf("Enter valid choice");
        }
    }
}

