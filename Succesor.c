#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right;
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
    }
    else{
        root->right = insert(root->right,data);
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
node* min(node* root)
{
    if(root->left!=NULL){
        min(root->left);
    }
    else{
        return root;
    }
}
node* successor(node* root,int data)
{
    node* current = search(root,data);
    if(current->right!=NULL){
        return min(current->right);
    }
    else{
        node* ancestor = root;
        node* successor = NULL;
        while(ancestor!=current){
            if(ancestor->value>current->value){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;

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
    node* suc = successor(root,52);
    printf("%p",suc);
    return 0;
}
