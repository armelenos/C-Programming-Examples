#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct LLNode
{
    int data;
    struct LLNode* next;
};


void traverseLL(struct LLNode* head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}


void Push(struct LLNode** head_ref,int data)
{
    struct LLNode* new_node=malloc(sizeof(struct LLNode));
    new_node->data=data;

    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}


void AddAfter(struct LLNode* prevNode,int data)
{
    if(prevNode==NULL)
        return;

    struct LLNode* new_node=malloc(sizeof(struct LLNode));
    new_node->data=data;

    new_node->next=prevNode->next;
    prevNode->next=new_node;
}


void Append(struct LLNode** head_ref,int data)
{
    if(*head_ref==NULL)
    {
        Push(head_ref,data);
        return;
    }

    struct LLNode* last=*head_ref;
    struct LLNode* new_node=malloc(sizeof(struct LLNode));
    new_node->data=data;
    new_node->next=NULL;

    while(last->next!=NULL)
    {
        last=last->next;
    }

    last->next=new_node;
}



bool Search(struct LLNode* head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
            return true;
        head=head->next;
    }
    return false;
}


bool SearchRecursive(struct LLNode* head,int key)
{
    if(head==NULL)
        return false;
    if(head->data==key)
        return true;
    return SearchRecursive(head->next,key);
}



int FindLength(struct LLNode* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}


int FindLengthRecursive(struct LLNode* head)
{
    if(head==NULL)
        return 0;
    return 1+FindLengthRecursive(head->next);
}




void deleteValue(struct LLNode** head_ref,int key)
{
    struct LLNode* head=*head_ref;
    struct LLNode* prev=head;
    struct LLNode* temp=head;

    if(head->data==key)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }

    else
    {
        while(temp->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
            return;

        prev->next=temp->next;

        free(temp);


    }
}




void DeleteAtPosition(struct LLNode** head_ref,int position)
{
    struct LLNode* head=*head_ref;
    struct LLNode* temp=*head_ref;
    struct LLNode* prev=*head_ref;

    if(position==0)
    {
        *head_ref=head->next;
        free(head);
        return;
    }

    int i;
    for(i=0;i<position;i++)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL || temp->next==NULL)
        return;


    prev->next=temp->next;
    free(temp);
}



int getNthNode(struct LLNode* head,int n)
{
    int i;
    struct LLNode* temp=head;
    for(i=0;i<n;i++)
    {
        temp=temp->next;
    }

    return temp->data;
}




int getNthNodeRecursive(struct LLNode* head,int n)
{
    if(head==NULL)
        return -1;

    if(n==0)
        return head->data;

    return getNthNode(head->next,n-1);
}

//length=8 n=2
int getLastNthNode(struct LLNode* head,int n)
{
    int i=0;
    struct LLNode* temp=head;
    int length=FindLength(head);

    for(i=0;i<length-n-1;i++)
        temp=temp->next;

    return temp->data;
}



int getMiddleElement(struct LLNode* head)
{
    struct LLNode* mid=head;
    int length=FindLength(head);
    int midLength=length/2;

    while(midLength)
    {
        mid=mid->next;
        midLength--;
    }

    return mid->data;
}


int getMiddleElement2(struct LLNode* head)
{
    struct LLNode* mid=head;
    int count=0;

    while(head!=NULL)
    {
        if(count&1)
        {
            mid=mid->next;
        }
        count++;
        head=head->next;
    }
    return mid->data;
}



int Occurences(struct LLNode* head,int key)
{
    int count=0;
    struct LLNode* current=head;
    while(current!=NULL)
    {
        if(current->data==key)
            count++;

        current=current->next;
    }
    return count;
}


bool isCircular(struct LLNode* head)
{
    if(head==NULL)
        return true;

    struct LLNode* current=head->next;
    while(current!=NULL && current!=head)
    {
        current=current->next;
    }

    return current==head;
}



void removeDuplicatesSorted(struct LLNode* head)
{
    struct LLNode* current=head;
    struct LLNode* next;
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            next=current->next->next;
            free(current->next);
            current->next=next;
        }
        else
            current=current->next;
    }
}



int main()
{
    struct LLNode* head=NULL;
    Push(&head,50);
    Push(&head,30);
    Push(&head,20);
    Push(&head,10);

    AddAfter(head->next->next->next,50);


    removeDuplicatesSorted(head);

    traverseLL(head);
    return 0;
}
