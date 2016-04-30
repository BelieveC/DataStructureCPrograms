#include<stdio.h>

int diff(int arr[],int x,int y)
{
    int k = arr[x]-arr[y];
    if(k<0){
        return k*(-1);
    }
    return k;
}
int main()
{
    int arr[] = {57393,29849,9283839,20202,2898929};
    printf("%d\n",diff(arr,1,3));
    return 0;
}
