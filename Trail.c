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
    if(top==SIZE-1){
        return 1;
    }
    return 0;
}
void push(int arr[],int*top,int value)
{
    if(!is_full(*top)){
        *top = *top+1;
        arr[*top] = value;
    }
}
int pop(int  arr[],int*top)
{
    if(!is_empty(*top)){
        int k = arr[*top];
        *top = *top -1;
        return k;
    }
}

void dfs(int arr[],char color[][2],int *top,int n,int adjmat[20][20])
{
    int k = pop(arr,top);
    int i;
    for(i=1;i<=n;i++){
        if(adjmat[k][i]==1 && (strcmp(color[i],"w")==0)){
            push(arr,top,i);
            strcpy(color[i],"g");
            dfs(arr,color,top,n,adjmat);
        }
    }
    strcpy(color[k],"b");
}

int main()
{
    int arr[SIZE];
    int top = 0;
    int adjmat[20][20];
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }
    char color[n+1][2];
    for(i=1;i<=n;i++){
        strcpy(color[i],"w");
    }
    strcpy(color[1],"g");
    push(arr,&top,1);
    dfs(arr,color,&top,n,adjmat);
    return 0;
}
