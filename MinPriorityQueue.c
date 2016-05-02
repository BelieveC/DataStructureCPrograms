#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    int prior;
}typedef node;

void minheapify(node arr[],int i,int size)
{
    int left = 2*i;
    int right = 2*i+1;
    int minimum = i;
    if(left<=size && arr[left].prior<arr[minimum].prior){
        minimum = left;
    }
    if(right<=size && arr[right].prior<arr[minimum].prior){
        minimum = right;
    }
    if(i!=minimum){
        swap(arr,i,minimum);
        minheapify(arr,minimum,size);
    }
}
void swap(node arr[],int x ,int y)
{
    int t1 = arr[x].value;
    int t2 = arr[x].prior;
    arr[x].value = arr[y].value;
    arr[x].prior = arr[y].prior;
    arr[y].value = t1;
    arr[y].prior = t2;
}

void insertkey(node arr[],int i,int key,int prior)
{
    if(key>arr[i].value){
        return;
    }
    arr[i].value = key;
    arr[i].prior = prior;
    while(i>1 && arr[i/2].prior > arr[i].prior){
        swap(arr,i,i/2);
        i = i/2;
    }

}
int minvalue(node arr[],int* size)
{
    int min = arr[1].value;
    swap(arr,1,*size);
    *size = *size - 1;
    minheapify(arr,1,*size);
    return min;
}
void insert(node arr[],int*size, int key, int prior)
{
    *size = *size + 1;
    arr[*size].value = 9999999;
    insertkey(arr,*size,key,prior);
}
int main()
{
    node arr[10];
    int size = 0;
    insert(arr,&size,3,3);
    printf("%d\n",arr[0].value);
    insert(arr,&size,2,2);
    printf("%d\n",arr[0].value);
    insert(arr,&size,4,4);
    printf("size = %d\n",size);
    printf("%d ",arr[0].value);
    printf("%d ",arr[1].value);
    printf("%d ",arr[2].value);
    return 0;
}
