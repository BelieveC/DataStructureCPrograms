#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    temp->value = data;
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
void inorder(node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->value);
        inorder(root->right);
    }
}
node* search(node* root,int data)
{
    if(root==NULL){
        return NULL;
    }
    else if(root->value==data){
        return root;
    }
    else if(root->value>=data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}
node* min(node* root)
{
    if(root->left!=NULL){
        min(root->left);
    }
    else{
        return root;
    }
}
node* max(node* root)
{
    if(root->right!=NULL){
        max(root->right);
    }
    else{
        return root;
    }
}
int lcheck(node* pos,int  val)
{
    if(val==pos->left->value){
        return 1;
    }
    return 0;
}
node* deletenode(node* root,int data)
{
    node* pos = search(root,data);
    if(pos->left==NULL && pos->right==NULL){
        if(lcheck(pos->parent,pos->value)){
            pos->parent->left = NULL;
        }
        else{
            pos->parent->right = NULL;
        }
    }
    else if(pos->left!=NULL && pos->right==NULL){
        if(lcheck(pos->parent,pos->value)){
            pos->parent->left = pos->left;
        }
        else{
            pos->parent->right = pos->left;
        }
    }
    else if(pos->left==NULL && pos->right!=NULL){
        if(lcheck(pos->parent,pos->value)){
            pos->parent->left = pos->right;
        }
        else{
            pos->parent->right = pos->right;
        }
    }
    else{
        node* maxi = max(pos->left);
        pos->value = maxi->value;
        deletenode(pos->left,maxi->value);
    }
}
void deltermnode(node* root)
{
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        printf("I am Here lets delete %d\n",root->value);
        deletenode(root,root->value);
         printf("I am Here delete complete\n");
    }
    else{
        deltermnode(root->left);
        deltermnode(root->right);
    }
}
int main()
{
    node* root = newnode(20);
    insert(root,3);
    insert(root,4);
    insert(root,238);
    insert(root,16);
    insert(root,182);
    insert(root,12);
    insert(root,28);
    inorder(root);
    deltermnode(root);
    return 0;
}
