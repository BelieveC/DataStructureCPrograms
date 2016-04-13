#include<stdio.h>
#include<stdlib.h>

struct subset{
    int rank;
    int parent;
}typedef subset;

int find_set(subset subset[],int i)
{
    int k = i;
    while(subset[i].parent!=i){
        i = subset[i].parent;
    }
    subset[k].parent = i;
    return i;
}
void make_set(subset subset[],int i)
{
    subset[i].rank = 0;
    subset[i].parent = i;
}

void make_union(subset subset[],int x,int y)
{
    if(subset[x].rank>subset[y].rank){
        int p1 = find_set(subset,y);
        int p2 = find_set(subset,x);
        subset[p1].parent = p2;
    }
    else if(subset[x].rank<subset[y].rank){
        int p1 = find_set(subset,y);
        int p2 = find_set(subset,x);
        subset[p2].parent = p1;
    }
    else{
        int p1 = find_set(subset,y);
        int p2 = find_set(subset,x);
        subset[p1].parent = p2;
        subset[p2].rank++;
    }
}

int main()
{
    subset* sub = (subset*)malloc(10*sizeof(subset));
    int i;
    printf("I am here\n");
    for(i=1;i<=10;i++){
        make_set(sub,i);
    }

    for(i=1;i<=10;i++){
        printf("%d %d\n",sub[i].parent,sub[i].rank);
    }
    make_union(sub,1,2);
    make_union(sub,2,3);
    make_union(sub,3,4);
    for(i=1;i<=10;i++){
        printf("%d %d\n",sub[i].parent,sub[i].rank);
    }
    for(i=1;i<=10;i++){
        printf("Parent of %d is %d\n",i,find_set(sub,i));
    }
    return 0;
}

