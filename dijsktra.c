#include<stdio.h>
#include<limits.h>
#define V 3
int mindis(int dist[],int sptSet[])
{
    int min = INT_MAX,min_index;
    int i;
    for(i=0;i<V;i++){
        if(dist[i] < min && sptSet[i]==0){
            min = dist[i],min_index = i;
        }
    }
    printf("I am in Mindis\n");
    return min_index;
}
void print(int dist[])
{
    int i;
    for(i=0;i<V;i++){
        printf("Index %d = %d\n",i,dist[i]);
    }

}
void dijsktra(int src,int arr[V][V])
{
    int dist[V];
    int i;
    for(i=0;i<V;i++){
        dist[i] = INT_MAX;
    }
    int sptSet[V];
    for(i=0;i<V;i++){
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for(i=0;i<V-1;i++){
        int min_index = mindis(dist,sptSet);
        sptSet[min_index] = 1;
        for(i=0;i<V;i++){
            if(dist[i]>dist[min_index]+ arr[min_index][i] && !sptSet[i] && arr[min_index][i]){
                dist[i] = dist[min_index]+arr[min_index][i];
            }
        }
    }
    print(dist);

}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[20][20];
    int i,j;
    for(i=0;i<n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dijsktra(0,arr);
    return 0;
}
