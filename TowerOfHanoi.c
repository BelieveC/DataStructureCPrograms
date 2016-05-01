#include<stdio.h>

void TOH(int n,char src[],char aux[],char dest[])
{
    if(n==1){
        printf("Move Disk-1 From %s to %s\n",src,dest);
        return;
    }
    TOH(n-1,src,dest,aux);
    printf("Move Disk-%d From %s to %s \n",n,src,dest);
    TOH(n-1,aux,src,dest);
}
int main()
{
    char src[] = "Source";
    char dest[] = "Destination";
    char aux[] = "Aux";
    TOH(3,src,aux,dest);
    return 0;
}
