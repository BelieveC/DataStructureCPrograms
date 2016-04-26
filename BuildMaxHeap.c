#include<stdio.h>
#define SIZE 20

struct node{
    int value;
    int prior;
}typedef node;

void maxheapify(node arr[],int i,int size)
{
    int left = 2i;
    int right = 2i+1;
    int largest = i;
    if(left<=size && arr[left].prior>arr[i].prior){
        largest = left;
    }
    if(right<=size && arr[right].prior>arr[largest].prior){
        largest = right;
    }
    if(largest!=i){
        swap(arr,i,largest);
        maxheapify(arr,largest,size);
    }
}
void swap(node arr[],int x,int y)
{
    int t1 = arr[x].value;
    int t2 = arr[x].prior;
    arr[x].value = arr[y].value;
    arr[x].prior = arr[y].prior;
    arr[y].prior = t2;
    arr[y].value = t1;
}

void buildheap(node arr[],int size)
{
    int i;
    for(i=size/2;i>=1;i--){
        maxheapify(arr,i,size);
    }
}
int main()
{
    node arr[10];
    int i;
    for(i=1;i<=9;i++){
        arr[i].value = i;
        arr[i].prior = i;
    }
    buildheap(arr,9);
    for(i=1;i<10;i++){
        printf("%d ",arr[i].value);
    }
    return 0;
}



