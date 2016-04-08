#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int adjmat[n+1][n+1];
    int i,j;
    int a,b;
    scanf("%d %d",&a,&b);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }

    if(adjmat[a][b]==1){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;


}
