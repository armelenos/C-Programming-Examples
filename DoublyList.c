#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct DLLNode
{
    int data;
    struct DLLNode* next;
    struct DLLNode* prev;
};




void push(struct DLLNode** head_ref,int data)
{
    struct DLLNode* new_node=malloc(sizeof(struct DLLNode));
    new_node->data=data;
    new_node->prev=NULL;

    new_node->next=*head_ref;

    if(*head_ref!=NULL)
    {
        (*head_ref)->prev=new_node;
    }

    (*head_ref)=new_node;
}



void AddAfter(struct DLLNode* prev_node,int data)
{
    if(prev_node==NULL)
        return;

    struct DLLNode* new_node=malloc(sizeof(struct DLLNode));
    new_node->data=data;

    new_node->next=prev_node->next;

    prev_node->next=new_node;

    new_node->prev=prev_node;

    if(new_node->next!=NULL)
        new_node->next->prev=new_node;
}



void Append(struct DLLNode** head_ref,int data)
{
    struct DLLNode* new_node=malloc(sizeof(struct DLLNode));
    new_node->data=data;
    new_node->next=NULL;

    if(*head_ref==NULL)
    {
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }

    struct DLLNode* last=*head_ref;

    while(last->next!=NULL)
        last=last->next;

    last->next=new_node;

    new_node->prev=last;
}



void traverseDLL(struct DLLNode* head)
{
    struct DLLNode* last;
    while(head!=NULL)
    {
        printf("%d",head->data);
        last=head;
        head=head->next;
    }

    printf("\n");

    while(last!=NULL)
    {
        printf("%d",last->data);
        last=last->prev;
    }
}



void deleteValueNode(struct DLLNode** head_ref,struct DLLNode* del)
{
    if(*head_ref==NULL || del==NULL)
        return;


    if(*head_ref==del)
        *head_ref=del->next;

    if(del->next!=NULL)
        del->next->prev=del->prev;

    if(del->prev!=NULL)
        del->prev->next=del->next;


    free(del);
}



void deletePosition(struct DLLNode** head_ref,int position)
{
    if(*head_ref==NULL || position<=0)
        return;

    struct DLLNode* del=*head_ref;
    int i;

    for(i=1;del!=NULL && i<position;i++)
        del=del->next;

    if(del==NULL)
        return;

    deleteValueNode(head_ref,del);
}



int SizeDLL(struct DLLNode* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}


int LargestData(struct DLLNode* head)
{
    struct DLLNode* current=head;
    struct DLLNode* max=head;

    while(current!=NULL)
    {
        if(current->data>max->data)
        {
            max=current;
        }
        current=current->next;
    }
    return max->data;
}



void PairsGivenSum(struct DLLNode* head,int x)
{
    struct DLLNode* current=head;
    struct DLLNode* current_next=head->next;

    while(current!=NULL)
    {
        struct DLLNode* temp=current->next;
        current_next=temp;
        while(current_next!=NULL)
        {
            if(current->data+current_next->data==x)
                printf("%d + %d = %d\n",current->data,current_next->data,x);
            current_next=current_next->next;
        }
        current=current->next;
    }

}



void PairsGivenSum2(struct DLLNode* head,int x)
{
    struct DLLNode* first=head;
    struct DLLNode* last=head;

    while(last->next!=NULL)
        last=last->next;

    while(first!=last && last->next!=first)
    {
        if(first->data+last->data==x)
        {
            printf("%d + %d = %d",first->data,last->data,x);
            first=first->next;
            last=last->next;
        }

        else
        {
            if(first->data+last->data<x)
                first=first->data;
            else
                last=last->prev;
        }
    }
}




bool isPalindrome(struct DLLNode* left)
{
    if(left==NULL)
        return true;

    struct DLLNode* right=left;
    while(right->next!=NULL)
        right=right->next;

    while(left!=right)
    {
        if(left->data!=right->data)
            return false;

        left=left->next;
        right=right->prev;
    }
    return true;
}


struct DLLNode* getNode(int data)
{
    struct DLLNode* newNode=malloc(sizeof(struct DLLNode));
    newNode->data=data;
    newNode->prev=newNode->next=NULL;
    return newNode;
};



void sortedInsert(struct DLLNode** head_ref,struct DLLNode* new_node)
{
    struct DLLNode* prev_node;

    if(*head_ref==NULL)
    {
        *head_ref=new_node;
    }

    else if((*head_ref)->data>new_node->data)
    {
        new_node->next=(*head_ref);
        new_node->next->prev=new_node;
        (*head_ref)=new_node;
    }

    else
    {
        prev_node=(*head_ref);
        while(prev_node->next!=NULL && prev_node->next->data<new_node->data)
            prev_node=prev_node->next;

        new_node->next=prev_node->next;

        if(new_node->next!=NULL)
            new_node->next->prev=new_node;

        prev_node->next=new_node;

        new_node->prev=prev_node;
    }
}


//12345
void leftRotateByN(struct DLLNode** head_ref,int n)
{
    if(n==0 || *head_ref==NULL)
        return;

    struct DLLNode* begin=*head_ref;
    struct DLLNode* last=*head_ref;

    while(last->next!=NULL)
        last=last->next;

    //Make Circular

    last->next=(*head_ref);
    (*head_ref)->prev=last;


    int i=0;
    while(i<n)
    {
        (*head_ref)=(*head_ref)->next;
        last=last->next;
        i++;
    }

    //Make Uncircular Again

    (*head_ref)->prev=NULL;
    last->next=NULL;
}



int countTriplets(struct DLLNode* head,int sum)
{
    struct DLLNode *ptr1,*ptr2,*ptr3;
    int count=0;

    for(ptr1=head;ptr1->next!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
        {
            for(ptr3=ptr2->next;ptr3!=NULL;ptr3=ptr3->next)
            {
                if(ptr1->data+ptr2->data+ptr3->data==sum)
                    count++;
            }
        }
    }
    return count;
}




void deleteAllOccurences(struct DLLNode** head_ref,int key)
{
    if(*head_ref==NULL)
        return;

    struct DLLNode* current=*head_ref;
    struct DLLNode* next;

    while(current!=NULL)
    {
        if(current->data==key)
        {
            next=current->next;
            deleteValueNode(head_ref,current);
            current=next;
        }
        else
            current=current->next;
    }
}



//1221
int main()
{
    struct DLLNode* head=NULL;

    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    push(&head, 2);
    push(&head, 2);


    deleteAllOccurences(&head,2);

    traverseDLL(head);

    return 0;
}
