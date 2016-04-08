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

void push(int a[],int val,int*top)
{
    if(!is_full(*top)){
        *top = *top+1;
        a[*top] = val;
        printf("Pushed Successfully!\n");
    }
}

int pop(int a[],int* top)
{
    if(!is_empty(*top)){
        *top = *top -1;
        printf("Popped Successfully!\n");
        return a[(*top)+1];
    }
}
int topelem(int a[],int top){
    return a[top];
}

void dfs(int a[],char color[][10],int *top,int n,int adjmat[100][100]){
    int k = topelem(a,*top);
    printf("%d\n",k);
    int i,j;
    for(i=1;i<=n;i++){
        if(adjmat[k][i] == 1){
            if(strcmp(color[i],"w")==0){
                push(a,i,top);
                strcpy(color[i],"g");
                dfs(a,color,top,n,adjmat);
            }

    }
    strcpy(color[k],"b");
    pop(a,top);
}
}
int main()
{
    int a[SIZE];
    int top = -1;
    int n;
    scanf("%d",&n);
    int src;
    scanf("%d",&src);
    int adjmat[100][100];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }
    char color[n][10];
    for(i=1;i<=n;i++){
        strcpy(color[i],"w");
    }
    int dis[n];
    for(i=1;i<=n;i++){
        dis[i] = 0;
    }
    push(a,src,&top);
    strcpy(color[src],"g");
    dfs(a,color,&top,n,adjmat);
    return 0;
}
