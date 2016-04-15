#include<stdio.h>
#define SIZE 20

void maxheapify(int heap[],int i)
{
    int l = 2i;
    int r = 2i+1;
    int largest = i;
    if(l<=SIZE && heap[l]>heap[largest]){
        largest = l;
    }
    if(r<=SIZE && heap[r]>heap[largest]){
        largest = r;
    }
    if(i!=largest){
        int temp = heap[largest];
        heap[largest] = heap[i];
        heap[i] = temp;
        maxheapify(heap,largest);
    }
}
void buildmax(int heap[])
{
    int i;
    for(i=SIZE/2;i>=1;i--){
        printf("I am here! %d\n",i);
        maxheapify(heap,i);
        printf("MaxHeap Complete %d\n",i);
    }
}
int main()
{
    int heap[SIZE+1];
    int i,j;
    for(i=1;i<=SIZE;i++){

        heap[i] = i;
    }
    buildmax(heap);
    return 0;
}
