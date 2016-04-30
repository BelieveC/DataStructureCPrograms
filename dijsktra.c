#include<stdio.h>
#include<limits.h>
int mindis(int dist[],int sptSet[],int n)
{
    int min = INT_MAX,min_index;
    int i;
    for(i=0;i<n;i++){
        if(dist[i] < min && sptSet[i]==0){
            min = dist[i],min_index = i;
        }
    }
    return min_index;
}
void print(int dist[],int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("Index %d = %d\n",i,dist[i]);
    }

}
void dijsktra(int src,int arr[20][20],int n)
{
    int dist[n];
    int i,j;
    for(i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    int sptSet[n];
    for(i=0;i<n;i++){
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for(i=0;i<n-1;i++){
        int u = mindis(dist,sptSet,n);
        sptSet[u] = 1;
        for(j=0;j<n;j++){
            if(!sptSet[j] && arr[u][j] && dist[j]>(dist[u]+ arr[u][j])){
                dist[j] = dist[u]+arr[u][j];
            }
        }
    }
    print(dist,n);

}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[20][20];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dijsktra(0,arr,n);
    return 0;
}
