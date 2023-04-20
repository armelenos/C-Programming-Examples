#include <stdio.h>
#include <stdlib.h>


struct CLNode
{
    int data;
    struct CLNode* next;
};


void traverse(struct CLNode* head)
{
    struct CLNode* temp=head;
    if(head)
    {
        do
        {
            printf("%d",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}



void push(struct CLNode** head_ref,int data)
{
    struct CLNode* new_node=malloc(sizeof(struct CLNode));
    new_node->data=data;
    new_node->next=*head_ref;

    if(*head_ref)
    {
        struct CLNode* last=*head_ref;
        while(last->next!=*head_ref)
            last=last->next;

        last->next=new_node;
    }
    else
        new_node->next=new_node;

    (*head_ref)=new_node;
}



struct CLNode* addToEmpty(struct CLNode** head_ref,int data)
{
    struct CLNode* head=*head_ref;
    if(*head_ref)
        return head;

    struct CLNode* newNode=malloc(sizeof(struct CLNode));

    newNode->data=data;

    *head_ref=newNode;

    newNode->next=newNode;

    return *head_ref;
}


struct CLNode* addAfter(struct CLNode** head_ref,int data,int item)
{
    if(*head_ref==NULL)
        return NULL;

    struct CLNode *new_node,*current;

    current=(*head_ref)->next;

    do
    {
        if(current->data==item)
        {
            new_node=malloc(sizeof(struct CLNode));
            new_node->data=data;

            new_node->next=current->next;

            current->next=new_node;

            if(current==*head_ref)
                *head_ref=current;

            return *head_ref;
        }
        current=current->next;
    }while(current!=(*head_ref)->next);
}




void Append(struct CLNode** head_ref,int data)
{
    struct CLNode* new_node=malloc(sizeof(struct CLNode));
    new_node->data=data;

    if(!(*head_ref))
    {
        *head_ref=new_node;
        new_node->next=*head_ref;
    }
    else
    {
        struct CLNode* last=*head_ref;
        while(last->next!=*head_ref)
            last=last->next;

        last->next=new_node;
        new_node->next=*head_ref;
    }
}


int getSize(struct CLNode* head)
{
    int count=1;
    struct CLNode* current=head->next;
    while(current!=head)
    {
        count++;
        current=current->next;
    }
    return count;
}




void deleteNode(struct CLNode** head_ref,int key)
{
    if(*head_ref==NULL)
        return;

    if((*head_ref)->data==key && (*head_ref)->next==*head_ref)
    {
        free(*head_ref);
        *head_ref=NULL;
        return;
    }

    struct CLNode* last=*head_ref;
    struct CLNode* d;

    if((*head_ref)->data==key)
    {
        while(last->next!=*head_ref)
            last=last->next;

        last->next=(*head_ref)->next;
        free(*head_ref);
        *head_ref=last->next;
        return;
    }

    while(last->next!=*head_ref && last->next->data!=key)
        last=last->next;

    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        return;
}




int main()
{
    struct CLNode* head=NULL;

    Append(&head,30);
    Append(&head,20);
    Append(&head,10);
    Append(&head,5);
    Append(&head,2);


    deleteNode(&head,20);

    traverse(head);
    return 0;
}
