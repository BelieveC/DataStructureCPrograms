#include<stdio.h>
#include<string.h>
#define SIZE 10
int is_empty(int front,int rear)
{
    if(rear == -1 && front == -1){
        return 1;
    }
    return 0;
}

int is_full(int front,int rear)
{
        if((++rear)%SIZE==front){
            return 1;

        }
        return 0;
}
void enqueue(int a[],int val,int *front,int*rear)
{
    if(!is_full(*front,*rear)){
        if(is_empty(*front,*rear)){
            *front=0;
            *rear=0;
            a[0] = val;

        }
        else{
            *rear+=1;
            a[(*rear)%SIZE]=val;
        }
    }
}

int dequeue(int a[],int *front,int*rear)
{
    if(!is_empty(*front,*rear)){
        if(*front == *rear){
            int m = a[*front];
            *front = -1;
            *rear = -1;
            return m;
        }
        else
        {
            int m = a[*front];
            *front = (++(*front))%SIZE;
            return m;


        }
    }
}
int main()
{
    int a[SIZE];
    int front = -1;
    int rear = -1;
    int n;
    printf("Enter the no the node of the graph\n");
    scanf("%d",&n);
    printf("\n");
    int adjmat[n+1][n+1];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }
    char color[n+1][10];
    for(i=1;i<=n;i++)
    {
        strcpy(color[i],"w");
    }
    int dis[n+1];
    for(i=1;i<=n;i++){
        dis[i] = 0;
    }
    printf("Enter the Source node\n");
    int src;
    scanf("%d",&src);
    enqueue(a,src,&front,&rear);
    while(!is_empty(front,rear)){
        int k = dequeue(a,&front,&rear);
        for(i=1;i<=n;i++){
            if(adjmat[k][i]==1){
                if(strcmp(color[i],"w")==0){
                    enqueue(a,i,&front,&rear);
                    strcpy(color[i],"g");
                }
            }
        }
        strcpy(color[k],"b");
        printf("%d\n",k);
    }
       return 0;
}
