#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node{
    int value;
    struct node*left,*right;
}typedef node;

node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
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
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->value);
        inorder(root->right);
    }
}
void preorder(node* root)
{
    if(root!=NULL){
        printf("%d\n",root->value);
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(node* root)
{
    if(root!=NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d\n",root->value);
    }
}
int main()
{
    node* a[SIZE];
    int top = -1;
    node* root = newnode(49);
    insert(root,3);
    insert(root,36);
    insert(root,54);
    insert(root,10);
    insert(root,13);
    insert(root,23);
    insert(root,73);
    insert(root,99);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
