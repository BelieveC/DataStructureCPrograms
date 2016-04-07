#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int adjmat[n+1][n+1];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
       }
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(adjmat[i][j]==1){
                printf("%d %d\n",i,j);
            }
        }
    }

    return 0;
}
