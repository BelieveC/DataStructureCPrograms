#include<stdio.h>
#define MAXQUEUE 10

int is_empty(int *front,int *rear)
{
    if(*front == -1 && *rear == -1)
    {
        return 1;
    }
    return 0;
}

int is_full(int *front,int *rear)
{
    if((*rear+1)%MAXQUEUE == *front){
        return 1;
    }
    return 0;
}

void enqueue(int a[],int *front,int * rear,int val)
{
    if(!is_full(front , rear))
    {
        if(is_empty(front, rear)){
            *rear = 0;
            *front = 0;
            a[*rear] = val;
        }
        else{
            *rear = (*rear + 1)%MAXQUEUE;
            printf("%d\n",*rear);
            a[*rear] = val;
        }
        printf("Enqueue Succesfully\n");
    }
    else{
            printf("Queue is FUll\n");
    }
}

void dequeue(int *rear,int *front)
{
    if(!is_empty(front,rear)){
        if(*front == *rear){
            *front = -1;
            *rear = -1;
        }
        else{
            *front = ((*front)+1)%MAXQUEUE;
        }
    }
    else{
    printf("Queue is Empty\n");
    }
}

int main()
{
    int a[MAXQUEUE];
    int front = -1;
    int rear = -1;
    printf("%d\n",is_empty(&front,&rear));
    printf("%d\n",is_full(&front,&rear));
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    enqueue(a,&front,&rear,2);
    printf("%d\n",rear);
    dequeue(&rear, &front);
    dequeue(&rear, &front);
    enqueue(a,&front,&rear,2);
    printf("%d\n",rear);
    enqueue(a,&front,&rear,2);
    printf("%d\n",rear);

    return 0;
}
