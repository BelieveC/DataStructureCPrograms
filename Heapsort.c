#include<stdio.h>
struct node{
    int value;
    int prior;
}typedef node;

void maxheapify(node arr[],int i,int size)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left<=size && arr[left].prior > arr[largest].prior){
        largest = left;
    }
    if(right<=size && arr[right].prior >arr[largest].prior){
        largest = right;
    }
    if(i!=largest){
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
    arr[y].value = t1;
    arr[y].prior = t2;
}
void buildmaxheap(node arr[],int size)
{
    int i;
    for(i=size/2;i>=1;i--){
        maxheapify(arr,i,size);
    }
}
void heapsort(node arr[],int size)
{
    int i;
    buildmaxheap(arr,size);
    for(i=size;i>1;i--){
        swap(arr,1,size);
        size = size-1;
        maxheapify(arr,1,size);
    }
}
int main()
{
    node arr[10];
    int i;
    for(i=1;i<10;i++){
        arr[i].value = i;
        arr[i].prior = i;
    }
    for(i=1;i<10;i++){
        printf("%d ",arr[i].value);
    }
    return 0;
}
