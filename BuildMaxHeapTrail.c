#include<stdio.h>
#include<stdlib.h>

void maxheapify(int arr[],int i,int size)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    if(l<=size && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<=size && arr[r]>arr[largest]){
        largest = r;
    }
    if(i!=largest){
        int k = arr[i];
        arr[i] = arr[largest];
        arr[largest] = k;
        maxheapify(arr,largest,size);
    }
}

void buildheap(int arr[],int size)
{
    int i;
    for(i=size/2;i>=1;--i){
        maxheapify(arr,i,size);
    }
}
int main()
{
    int arr[10];
    int i;
    for(i=1;i<10;i++){
        arr[i] = i;
    }
     buildheap(arr,9);
    for(i=1;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
