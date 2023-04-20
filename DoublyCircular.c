#include <stdio.h>
#include <stdlib.h>


struct DCLNode
{
    int data;
    struct DCLNode* next;
    struct DCLNode* prev;
};



void insertBegin(struct DCLNode** head_ref, int value)
{
    struct DCLNode* last;

    struct DCLNode* new_node = malloc(sizeof(struct DCLNode));
    new_node->data = value;

    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        new_node->next=*head_ref;
        new_node->prev=*head_ref;
    }
    else
    {
        last=*head_ref;
        while(last->next!=*head_ref)
            last=last->next;

        last->next=new_node;
        new_node->prev=last;

        (*head_ref)->prev=new_node;

        new_node->next=*head_ref;

        *head_ref=new_node;
    }
}



void insertEnd(struct DCLNode** head_ref,int data)
{
    struct DCLNode* new_node=malloc(sizeof(struct DCLNode));
    new_node->data=data;


    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        new_node->next=*head_ref;
        new_node->prev=*head_ref;
        return;
    }

    struct DCLNode* last=(*head_ref)->prev;
    new_node->next=*head_ref;

    (*head_ref)->prev=new_node;

    new_node->prev=last;

    last->next=new_node;
}



void insertAfter(struct DCLNode* head,int data,int value)
{
    struct DCLNode* new_node=malloc(sizeof(struct DCLNode));
    new_node->data=data;

    struct DCLNode* current=head;
    while(current->data!=value)
        current=current->next;

    struct DCLNode* next=current->next;

    current->next=new_node;
    new_node->prev=current;

    new_node->next=next;
    next->prev=new_node;
}


void display(struct DCLNode* head)
{
    struct DCLNode* current=head;
    while(current->next!=head)
    {
        printf("%d",current->data);
        current=current->next;
    }

    printf("%d",current->data);

    printf("\n\n");

    struct DCLNode* last=head->prev;
    current=last;

    while(current->prev!=last)
    {
        printf("%d",current->data);
        current=current->prev;
    }

    printf("%d",current->data);
}



int search(struct DCLNode* head,int x)
{
    struct DCLNode* temp=head;
    int count=0,flag=0,value;

    if(!temp)
        return -1;
    else
    {
        while(temp->next!=head)
        {
            count++;

            if(temp->data==x)
            {
                flag=1;
                count--;
                break;
            }
            temp=temp->next;
        }

        if(temp->data==x)
        {
            count++;
            flag=1;
        }
    }

    if(flag)
        return count;
    else
        return -1;
}




void deleteNode(struct DCLNode** head_ref,int key)
{
    if(*head_ref==NULL)
        return;

    struct DCLNode* current=*head_ref;
    struct DCLNode* prev=NULL;

    while(current->data!=key)
    {
        if(current->next==*head_ref)
            return;

        prev=current;
        current=current->next;
    }

    if(current->next==*head_ref && prev==NULL)
    {
        (*head_ref)=NULL;
        free(current);
        return;
    }


    if(current==*head_ref)
    {
        prev=(*head_ref)->prev;
        (*head_ref)=(*head_ref)->next;
        prev->next=*head_ref;
        (*head_ref)->prev=prev;
        free(current);
    }

    else if(current->next==*head_ref)
    {
        prev->next=*head_ref;
        (*head_ref)->prev=prev;
        free(current);
    }

    else
    {
        struct DCLNode* temp=current->next;

        prev->next=temp;
        temp->prev=prev;
        free(current);
    }
}




int main()
{
    struct DCLNode* head=NULL;

    insertBegin(&head,30);
    insertBegin(&head,20);
    insertBegin(&head,10);

    insertEnd(&head,40);

    insertAfter(head,50,40);

    deleteNode(&head,10);

    display(head);

    return 0;
}
