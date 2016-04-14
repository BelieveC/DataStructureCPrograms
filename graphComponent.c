#include<stdio.h>
#define SIZE 10
#include<string.h>
int is_empty(int top)
{
    if(top==-1){
        return 1;
    }
    return 0;
}
int is_full(int top)
{
    if(top==SIZE){
        return 1;
    }
    return 0;
}
int push(int a[],int*top,int val)
{
    if(!is_full(*top)){
        *top = *top + 1;
        a[*top] = val;
    }
}
int pop(int a[],int*top)
{
    if(!is_empty(*top)){
        int m = a[*top];
        *top = *top -1;
        return m;
    }
}
void dfs(int a[],int adjmat[100][100],int*top,int n,char color[][2])
{
    int i;
    int k = pop(a,top);
    for(i=1;i<=n;i++){
            if(adjmat[k][i]==1){
                if(strcmp(color[i],"w")==0){
                    push(a,top,i);
                    strcpy(color[i],"g");
                    dfs(a,adjmat,top,n,color);
                }
            }
    }
    strcpy(color[k],"b");
}
int main()
{
    int a[SIZE];
    int n,src,i,j,top = -1;
    scanf("%d",&n);
    int adjmat[100][100];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }

    char color[n+1][2];
    for(i=1;i<=n;i++){
        strcpy(color[i],"w");
    }
    int count=0;
    for(i=1;i<=n;i++){
        if(strcmp(color[i],"w")==0){
            push(a,&top,i);
            strcpy(color[i],"g");
            dfs(a,adjmat,&top,n,color);
            count++;
        }
    }
    printf("total = %d",count);
    return 0;
}
