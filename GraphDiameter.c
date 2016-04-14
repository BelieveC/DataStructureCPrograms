#include<stdio.h>
#include<string.h>
#define SIZE 10

int is_empty(int front,int rear)
{
    if(front == -1 && rear == -1){
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
void enqueue(int a[],int val,int* front,int*rear)
{
    if(!is_full(*front,*rear)){
        if(is_empty(*front,*rear)){
            *rear = 0;
            *front =0;
            a[*rear] = val;
        }
        else{
            *rear = (*rear +1)%SIZE;
            a[*rear] = val;
        }
    }
}

int dequeue(int a[],int*front,int* rear)
{
    if(!is_empty(*front,*rear)){
        if(*front == *rear){
            int m = a[*front];
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
int main()
{
    int a[SIZE];
    int front = -1,rear = -1;
    int n,src,i,j;
    scanf("%d",&n);
    int adjmat[n+1][n+1];
    char color[n+1][2];
    int dis[n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
        strcpy(color[i],"w");
        dis[i]=0;
    }
    enqueue(a,1,&front,&rear);
    strcpy(color[1],"g");
    while(!is_empty(front,rear)){
        int k = dequeue(a,&front,&rear);
        for(i=1;i<=n;i++){
            if(adjmat[k][i]==1){
                if(strcmp(color[i],"w")==0){
                    enqueue(a,i,&front,&rear);
                    strcpy(color[i],"g");
                    dis[i] = dis[k] + 1;
                }
            }
        }
        printf("%d at Dis = %d\n",k,dis[k]);
        strcpy(color[k],"b");
    }
    int largest = 1;

    for(i=1;i<=n;i++){
        if(dis[i]>dis[largest]){
            largest = i;
        }
    }
    printf("Largest = %d\n",largest);
    for(i=1;i<=n;i++){
        strcpy(color[i],"w");
        dis[i] = 0;
    }
    enqueue(a,largest,&front,&rear);
    strcpy(color[largest],"g");
     while(!is_empty(front,rear)){
        int k = dequeue(a,&front,&rear);
        for(i=1;i<=n;i++){
            if(adjmat[k][i]==1){
                if(strcmp(color[i],"w")==0){
                    enqueue(a,i,&front,&rear);
                    strcpy(color[i],"g");
                    dis[i] = dis[k] + 1;
                }
            }
        }
        printf("%d at Dis = %d\n",k,dis[k]);
        strcpy(color[k],"b");
    }
    largest = 1;
     for(i=1;i<=n;i++){
        if(dis[i]>dis[largest]){
            largest = i;
        }
    }
    printf("Largest = %d\n",largest);
    printf("%d",dis[largest]);

    return 0;
}
