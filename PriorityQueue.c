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
    int left = 2i;
    int right = 2i+1;
    int largest = i;
    if(left<=size && a[left].prior>a[i].prior){
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
void buildmaxheap(node a[],int size)
{
    int i;
    for(i=size/2;i>=1;i--){
        maxheapify(a,i,size);
    }
}
int main()
{
    int i;
    node a[10];
    for(i=1;i<=9;i++){
        a[i].value = i;
        a[i].prior = i;
    }
    buildmaxheap(a,9);
    return 0;
}
