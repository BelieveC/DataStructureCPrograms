#include<stdio.h>

void maxheapify(int arr[],int i,int size,int* count)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left<=size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<=size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        *count = *count + 1;
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxheapify(arr,largest,size,count);
    }
}

void buildmaxheap(int arr[],int size,int* count)
{
    int i;
    for(i=size/2;i>=1;i--){
        maxheapify(arr,i,size,count);
    }
}

int main()
{
    int count = 0;
    int arr[13] = {89, 19, 50, 17, 12, 15, 2, 5, 7, 11, 6, 9, 100};
    buildmaxheap(arr,12,&count);
    printf("%d\n",count);
    return 0;
}
