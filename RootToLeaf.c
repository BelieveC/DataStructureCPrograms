#include<stdio.h>
#include<stdlib.h>
#define NL printf("\n")
struct node{
    int value;
    struct node* left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = data;
    temp->right = NULL;
    temp->left = NULL;
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
    else {
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}

node* search(node* root,int data)
{
    if(root==NULL){
        return NULL;
    }
    else if(root->value == data){
        return root;
    }
    else if(root->value>=data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}
void RootToLeaf(node* root,int index,int arr[])
{
    int i;
    if(root->left==NULL && root->right==NULL){
        arr[index] = root->value;
        for(i=0;i<=index;i++){
            printf("%d_",arr[i]);
        }
        NL;
        return;
    }
    else if(root->left!=NULL && root->right==NULL){
        arr[index] = root->value;
        index++;
        int temp[index+1];
        for(i=0;i<=index;i++){
            temp[i] = arr[i];
        }
        RootToLeaf(root->left,index,temp);
        return;
    }
    else if(root->right!=NULL && root->left==NULL){
        arr[index] = root->value;
        index++;
        int temp[index+1];
        for(i=0;i<=index;i++){
            temp[i] = arr[i];
        }
        RootToLeaf(root->right,index,temp);
        return;
    }
    else{
        arr[index] = root->value;
        index++;
        int temp1[index+1];
        int temp2[index+1];
        for(i=0;i<=index;i++){
            temp1[i] = arr[i];
            temp2[i] = arr[i];
        }
        RootToLeaf(root->left,index,temp1);
        RootToLeaf(root->right,index,temp2);
        return;
    }

}
node* max(node* root)
{
    if(root->right==NULL){
        return root;
    }
    root = root->right;

}
node* min(node* root)
{
    if(root->left==NULL){
        return root;
    }
    root = root->left;

}
void numofleaf(node* root,int* count)
{
    if(root==NULL){
        return ;
    }
    else if(root->left==NULL && root->right==NULL){
        *count = *count+1;
    }
    numofleaf(root->left,count);
    numofleaf(root->right,count);
}

int main()
{
     node* root = newnode(2);
     root->parent = root;
    insert(root,1);
    insert(root,4);
    insert(root,3);
    int count=0;
    numofleaf(root,&count);
    printf("%d\n",count);
    NL;
    int arr[1];
    RootToLeaf(root,0,arr);
    return 0;
}
