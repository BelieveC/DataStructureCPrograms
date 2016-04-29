#include<stdio.h>
#include<limits.h>
#define V 9
int mindis(int dist[],int sptSet[])
{
    int min = INT_MAX,min_index;
    int i;
    for(i=0;i<V;i++){
        if(dist[i]<min && sptSet[i]==0){
            min = dist[i],min_index = i;
        }
    }
    return min_index;
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
        sptSet[V] = 0;
    }
    dist[src] = 0;
    for(i=0;i<V-1;i++){
        int min_index = mindis(dist,sptSet);
        sptSet[min_index] = 1;
        for(i=0;i<V;i++){
            if(arr[min_index][i])
        }
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[20][20];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}
