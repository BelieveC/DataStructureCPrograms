#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node*left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node* temp =(node*)malloc(sizeof(node));
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* insert(node* root,int data)
{
    if(root==NULL){
        root = newnode(data);
    }
    else if(root->value>=data){
        root->left = insert(root->left,data);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}
void inorder(node* root,int arr[],int* count)
{
    if(root!=NULL){
        inorder(root->left,arr,count);
        *count = *count + 1;
        arr[*count] = root->value;
        inorder(root->right,arr,count);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    node* root1 = NULL;
    node* root2 = NULL;
    int i,temp,j;
    int a1[m];
    int a2[m];
    int result[n];

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&temp);
            root1 = insert(root1,temp);
        }
        for(j=0;j<m;j++){
            scanf("%d",&temp);
            root2 = insert(root2,temp);
        }
    temp = -1;
    inorder(root1,a1,&temp);
    temp = -1;
    int flag = 0;
    inorder(root2,a2,&temp);
    for(j=0;j<m;j++){
       if(a1[j]!=a2[j]){
            flag = 1;
            break;
            }
       }
    if(flag==1){
        result[i] =0;
    }
    else{
        result[i] = 1;
    }
}
    for(i=0;i<n;i++){
        if(result[i]==1){
            printf("y\n");
        }
        else{
            printf("n\n");
        }
    }



     return 0;
}
