#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node*left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = data;
    temp->left =NULL;
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
node* InorderToBST(node* root,int arr[],int start,int end)
{
        if(start<=end){
        int mid = (start+end)/2;
        root = insert(root,arr[mid]);
        InorderToBST(root,arr,start,mid-1);
        InorderToBST(root,arr,mid+1,end);
        }
        else{
            return root;
        }
}
void inorder(node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d_",root->value);
        inorder(root->right);
    }
}
void postorder(node* root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d_",root->value);
    }
}
int main()
{
    int arr[5] = {1,2,3,8,9};
    node* root = NULL;
    root = InorderToBST(root,arr,0,4);
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
