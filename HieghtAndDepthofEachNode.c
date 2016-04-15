#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right,*parent,*hieght,*depth;
}typedef node;
node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));\
    temp->left = NULL;
    temp->right = NULL;
    temp->value =data;
    return temp;
}
node* insert(node* root,int data)
{
    if(root==NULL){
        root = newnode(data);
    }
    else if(root->value>= data){
        root->left = insert(root->left,data);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}
int height(node* root,int count)
{
    if(root==NULL){
        return 0;
    }
    else{
        root->depth = count;
        count++;
        int l = height(root->left,count);
        int r = height(root->right,count);
        int h = l>r?l:r;
        root->hieght = h;
        return ++h;
    }
}
void inorder(node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("Value = %d and Hieght = %d and Depth = %d\n",root->value,root->hieght,root->depth);
        inorder(root->right);
    }
}
int main()
{
    node* root = newnode(29);
    insert(root,3);
    insert(root,52);
    insert(root,12);
    insert(root,23);
    insert(root,31);
    insert(root,17);
    insert(root,2);
    insert(root,9);
    height(root,0);
    inorder(root);
    return 0;
}

