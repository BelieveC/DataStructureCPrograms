#include<stdio.h>
#include<string.h>
#define SIZE 10

int is_empty(int top)
{
    if(top==-1){
        return 1;
    }
    return 0;
}
int is_full(int top)
{
    if(top == SIZE-1){
        return 1;
    }
    return 0;
}
void push(int a[],int val,int* top)
{
    if(!is_full(*top)){
        *top = *top+1;
        a[*top] = val;
    }
}
void pop(int *top)
{
    if(!is_empty){
        *top = *top -1;
    }
}

int topelem(int a[],int top)
{
    return a[top];
}
int dfs(int a[],int adjmat,int )
int main()
{
    int a[SIZE];
    int top = -1;
    int n;
    scanf("%d",&n);
    int adjmat[n+1][n+1];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }

    return 0;
}
