#include<stdio.h>
#define SIZE 21
int parent(int i)
{
    return 2*i;
}
int lchild(int i)
{
    return 2*i;
}
int rchild(int i)
{
    return 2*i+1;
}
void maxheapify(int heap[],int i)
{
    int lc = 2*i;
    int rc = 2*i+1;

    int largest = i;
    if(lc<SIZE && heap[lc]>heap[i]){
        largest = lc;
    }
    if(rc<SIZE && heap[rc]>heap[largest]){
        largest = rc;
    }
    if(i!=largest){
        int temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;
        maxheapify(heap,largest);
    }
}
int main()
{
    int heap[20];
    return 0;
}
