#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};



struct Stack* createStack(unsigned capacity)
{
    struct Stack* newStack=malloc(sizeof(struct Stack));
    newStack->capacity=capacity;
    newStack->top=-1;
    newStack->array=malloc(newStack->capacity*sizeof(int));
    return newStack;
}



bool isFull(struct Stack* stack)
{
    return stack->top==stack->capacity-1;
}


bool isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}


void push(struct Stack* stack,int item)
{
    if(isFull(stack))
        return;

    stack->array[++stack->top]=item;

}


int pop(struct Stack* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}


int peek(struct Stack* stack)
{
    return stack->array[stack->top];
}



char* reverseString(char str[])
{
    char *p=str;
    struct Stack* stack=createStack(100);
    int i;

    for(i=0;p[i]!='\0';i++)
    {
        push(stack,p[i]);
    }

    for(i=0;i<strlen(str);i++)
    {
        str[i]=pop(stack);
    }
    return str;
}



void reverseIndiviualWords(char str[])
{
    int length=strlen(str),i;
    struct Stack* stack=createStack(100);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
            push(stack,str[i]);

        else
        {
            while(isEmpty(stack)==false)
            {
                printf("%c",peek(stack));
                pop(stack);
            }
            printf(" ");
        }
    }

    while(isEmpty(stack)==false)
    {
        printf("%c",peek(stack));
        pop(stack);
    }
}



void PushArray(int array[],int n)
{
    struct Stack* s=createStack(100);
    struct Stack* stack=createStack(100);
    int i;
    for(i=0;i<n;i++)
    {
        push(stack,array[i]);
    }

    for(i=0;i<n;i++)
    {
        s->array[n-i-1]=peek(stack);
        pop(stack);
    }

    for(i=0;i<n;i++)
    {
        printf("%d",s->array[i]);
    }
}


int SizeofStack(struct Stack* stack)
{
    int count=0;
    while(!isEmpty(stack))
    {
        count++;
        pop(stack);
    }

    return count;
}



void DesignStackWhichReturnsMinumumElementPush(struct Stack* stack,struct Stack* aux,int data)
{
    push(stack,data);

    if(isEmpty(aux))
        push(aux,data);
    else
    {
        if(peek(aux)>=data)
            push(aux,data);
    }
}


void DesignStackWhichReturnsMinumumElementPop(struct Stack* stack,struct Stack* aux)
{
    int top=peek(stack);
    pop(stack);

    if(top==peek(aux))
        pop(aux);

    return top;
}


int getMin(struct Stack* stack)
{
    return peek(stack);
}


struct Stack2
{
    int top1,top2;
    unsigned capacity;
    int* array;
};



struct Stack2* createStack2(unsigned capacity)
{
    struct Stack2* stack2=malloc(sizeof(struct Stack2));
    stack2->capacity=capacity;
    stack2->top1=capacity/2+1;
    stack2->top2=capacity/2;
    stack2->array=malloc(stack2->capacity*sizeof(int));
    return stack2;
}

//
void push2(struct Stack2* stack2,int item)
{
    if(stack2->top1>0)
    {
        stack2->array[--stack2->top1]=item;
        printf("%d pushed to arr1\n",stack2->array[stack2->top1]);
    }
    else
    {
        printf("Stack overflow\n");
        return;
    }
}



void push3(struct Stack2* stack2,int item)
{
    if(stack2->top2<stack2->capacity-1)
    {
        stack2->array[++stack2->top2]=item;
        printf("%d pushed to arr2\n",stack2->array[stack2->top2]);

    }
    else
    {

        printf("Stack Overflow\n");
        return;
    }
}


int pop2(struct Stack2* stack2)
{
    if(stack2->top1<=stack2->capacity/2)
    {
        int x=stack2->array[stack2->top1++];
        //printf("%d popped from arr1\n",x);
        return x;
    }
    else
        printf("Stack undeflow\n");
}


int pop3(struct Stack2* stack2)
{
    if(stack2->top2>=stack2->capacity/2+1)
    {
        int x=stack2->array[stack2->top2--];
        //printf("%d popped from arr2",x);
        return x;
    }
}


//10 4 6 3 5
void findGreaterElementsRight(int arr[],int n)
{
    struct Stack* stack=createStack(n);
    int i;

    for(i=0;i<n;i++)
    {
        while(!isEmpty(stack) && peek(stack)<arr[i])
        {
            pop(stack);
        }
        push(stack,arr[i]);
    }

    while(!isEmpty(stack))
    {
        printf("%d",peek(stack));
        pop(stack);
    }
}




void findNextGreaterElements(int arr[],int n)
{
    struct Stack* stack=createStack(n);
    int i;

    for(i=0;i<n;i++)
    {
        while(!isEmpty(stack) && arr[peek(stack)]<arr[i])
        {
            arr[peek(stack)]=arr[i];
            pop(stack);
        }
        push(stack,i);
    }


    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        pop(stack);
    }
}




int main()
{

    int arr[]={ 2, 7, 3, 5, 4, 6, 8 };

    findNextGreaterElements(arr,8);
}
