#include<stdio.h>

void minheapify(int arr[],int i,int size)
{
    int left = 2*i;
    int right = 2*i+1;
    int minimum = i;
    if(left<=size && arr[minimum]>arr[left]){
        minimum = left;
    }
    if(right<=size && arr[minimum]>arr[right]){
        minimum = right;
    }
    if(minimum!=i){
        int k = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = k;
        minheapify(arr,minimum,size);
    }
}
void buildminheap(int arr[],int size)
{
    int i;
    for(i=size/2;i>=1;i--){
        minheapify(arr,i,size);
    }
}
int main()
{
    int arr[10],i;
    for(i=1;i<10;i++){
        arr[i] = i;
    }
    buildminheap(arr,9);
    for(i=1;i<10;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
