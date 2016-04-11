#include<stdio.h>
struct node{
    int value;
    struct node* left,*right;
}typedef node;

node* newnode(int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node *root,int x)
{
    if(root==NULL){
        printf("Newnode Added\n");
        root = newnode(x);
    }
    else if(root->value>=x){
        root->left = insert(root->left,x);
    }
    else{
        root->right = insert(root->right,x);
    }
    return root;
}
void print(node* root)
{
    if(root!=NULL){
        print(root->left);
        printf("%d\n",root->value);
        print(root->right);
    }
}
node* search(node*root,int x)
{
    if(root==NULL){
        printf("Number is not present in BST\n");
        return NULL;
    }
    else if(root->value==x){
        return root;
    }
    else if(root->value>= x)
    {
        search(root->left,x);
    }
    else if(root->value<x){
        search(root->right,x);
    }

}

int main()
{
    node* root = (node*)malloc(sizeof(node));
    root->value = 2;
    root->left =NULL;
    root->right = NULL;
    insert(root,3);
    insert(root,4);
    insert(root,5);
    printf("%p",search(root,7));


}
