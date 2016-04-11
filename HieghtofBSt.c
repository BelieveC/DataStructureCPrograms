#include<stdio.h>
struct node{
    int value;
    struct node* left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
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
}
int height(node* root)
{
    int h;
    if(root==NULL)
    {
        return 0;
    }
    else{
        int left = height(root->left);
        int right = height(root->right);
         h = left>right?left:right;
    }
        return ++h;
}
int main()
{
     node* root = newnode(2);
     root->parent = root;
    insert(root,1);
    insert(root,4);
    insert(root,3);
    printf("%d\n",height(root));
    return 0;
}
