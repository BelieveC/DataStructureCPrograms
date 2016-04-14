#include<stdio.h>
#include<string.h>
#define SIZE 10
int is_empty(int front,int rear)
{
    if(front==-1 && rear==-1){
        return 1;
    }
    return 0;
}
int is_full(int front,int rear)
{
    if((rear+1)%SIZE==front){
        return 1;
    }
    return 0;
}
void enqueue(int a[],int val,int*front,int*rear)
{
    if(!is_full(*front,*rear)){
        if(is_empty(*front,*rear)){
            *front = 0;
            *rear = 0;
            a[*front] = val;
        }
        else{
            *rear = (*rear+1)%SIZE;
            a[*rear] = val;
        }
    }
}
int dequeue(int a[],int*front,int*rear)
{
    if(!is_empty(*front,*rear)){
        if(*front==*rear){
            int m = a[*rear];
            *front = -1;
            *rear = -1;
            return m;
        }
        else{
            int m = a[*front];
            *front = (*front+1)%SIZE;
            return m;
        }
    }
}
void colorwhite(char color[][2],int n)
{
    int i;
    for(i=1;i<=n;i++){
        strcpy(color[i],"w");
    }
}
void bfs(int a[],int *front,int*rear,int adjmat[100][100],char color[][2],int n)
{
    while(!is_empty(*front,*rear)){
        int k = dequeue(a,front,rear);
        int i;
        for(i=1;i<=n;i++){
            if(adjmat[k][i]==1){
                if(strcmp(color[i],"w")==0){
                    enqueue(a,i,front,rear);
                    strcpy(color[i],"g");
                }
            }
        }
        strcpy(color[k],"b");
    }
}
int check(char color[][2],int n)
{
    int i;
    for(i=1;i<=n;i++){
        if(strcmp(color[i],"w")==0){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int a[SIZE];
    int front=-1,rear=-1;
    int n,i,j,flag;
    scanf("%d",&n);
    int adjmat[100][100];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }
    char color[n+1][2];
    for(i=1;i<=n;i++){
        colorwhite(color,n);
        if(i!=n){
            enqueue(a,i+1,&front,&rear);
        }
        else{
            enqueue(a,i-1,&front,&rear);
        }
         strcpy(color[i],"k");
         bfs(a,&front,&rear,adjmat,color,n);
         if(check(color,n)==1){
            flag = i;
            break;
         }
         flag =0;
    }
    if(flag!=0){
        printf("Articulation point is = %d",flag);
    }
    else{
        printf("No Articulation Point!");
    }


    return 0;
}
