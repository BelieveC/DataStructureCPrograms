#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* left,*right,*parent;
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
node* search(node* root,int data)
{
    if(root==NULL){
        return NULL;
    }
    else if(root->value == data){
        return root;
    }
    else if(root->value>= data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }

}

void print (node* root)
{
    if(root!=NULL){
        print(root->left);
        printf("%d\n",root->value);
        print(root->right);
    }
}
void sumofleaf(node* root,int* sum)
{
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        *sum = *sum + root->value;
    }
    sumofleaf(root->left,sum);
    sumofleaf(root->right,sum);
}
int main()
{
    node* root = newnode(4);
    insert(root,7);
    insert(root,8);
    insert(root,9);
    insert(root,3);
    insert(root,8);
    int sum =0;
    print(root);
    sumofleaf(root,&sum);

    printf("%d\n",sum);
    return 0;
}
