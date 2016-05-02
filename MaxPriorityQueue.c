#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    int prior;
}typedef node;
void swap(node a[],int x,int y)
{
    int t1,t2;
    t1 = a[x].value;
    t2 = a[x].prior;
    a[x].value = a[y].value;
    a[x].prior = a[y].prior;
    a[y].value = t1;
    a[y].prior = t2;
}
void maxheapify(node a[],int i,int size)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left<=size && a[left].prior>a[largest].prior){
        largest = left;
    }
    if(right<=size && a[right].prior>a[largest].prior){
        largest = right;
    }
    if(largest!=i){
        swap(a,i,largest);
        maxheapify(a,largest,size);
    }

}
void insertkey(node arr[],int i,int key,int prior)
{
    if(arr[i].value>key){
        return;
    }
    arr[i].value = key;
    arr[i].prior = prior;
    while(i>1 && arr[i/2].prior<arr[i].prior){
        swap(arr,i,i/2);
        i = i/2;
    }
}
int maxvalue(node arr[],int* size)
{
    if(*size<1){
        return;
    }
    int max = arr[1].value;
    swap(arr,1,*size);
    *size = *size -1;
    maxheapify(arr,1,*size);
    return max;
}
void insert(node arr[],int* size,int key,int prior)
{
    *size = *size + 1;
    arr[*size].value = -999999;
    insertkey(arr,*size,key,prior);
}
int main()
{
    int i,key,prior;
    node arr[10];
    int size = 0;
    for(i=1;i<=5;i++){
        scanf("%d %d",&key,&prior);
        insert(arr,&size,key,prior);
    }
    for(i=1;i<=5;i++){
        printf("%d ",maxvalue(arr,&size));
    }
    return 0;
}
