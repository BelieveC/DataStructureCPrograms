#include<stdio.h>

int parent(int i)
{
    return i/2;
}
int leftchild(int i)
{
    return 2i;
}
int rightchild(int i)
{
    return 2i+1;
}

int main()
{
    int heap[21];
    int i,j;
    for(i=20,j=1;j<=20;i--,j++){
        heap[j] = i;
    }
    printf("Parent 10 is %d\n",heap[parent(10)]);
    return 0;
}
