#include<stdio.h>
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

void preorder(node* root)
{
    if(root!=NULL){
        printf("%d_",root->value);
        preorder(root->left);
        preorder(root->right);
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
    preorder(root);
    NL;
    inorder(root);
    NL;
    postorder(root);
    NL;
    int count=0;
    numofleaf(root,&count);
    printf("%d\n",count);
    return 0;
}
