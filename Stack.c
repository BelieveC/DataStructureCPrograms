#include<stdio.h>
#define SIZE 4
int is_empty(int top)
{
    if(top==-1){
        return 1;
    }
    return 0;
}
int is_full(int top)
{
    if(top==SIZE-1){
        return 1;
    }
    return 0;
}
void push(int arr[],int* top,int val)
{
    if(!is_full(*top)){
        *top = *top + 1;
        arr[*top] = val;
    }
}
int pop(int arr[],int* top)
{
    if(!is_empty(*top)){
        int k = arr[*top];
        *top = *top - 1;
        return k;
    }
}
int main()
{
    int arr[SIZE];
    int top = -1;
    push(arr,&top,23);
    push(arr,&top,65);
    push(arr,&top,21);
    push(arr,&top,34);
    push(arr,&top,24);
    printf("Top = %d and %d\n",top,is_full(top));
    return 0;
}
