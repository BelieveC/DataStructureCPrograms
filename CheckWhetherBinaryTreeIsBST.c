#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right,*parent;
}typedef node;

node* newnode(int data)
{
    node*temp = (node*)malloc(sizeof(node));
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
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}
int check(node* root)
{
    if(root==NULL){
        return 1;
    }
    else{
        if(root->left->value>root->value || root->right->value<=root->value){
            return 0;
        }
        else{
            check(root->left);
            check(root->right);
        }
    }
}

int main()
{
    node* root = newnode(2);
    insert(root,2);
    insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,4);
    insert(root,6);
    /*if(check(root)){
        printf("Yes");
    }
    else{
        printf("No");
    }*/
    return 0;
}
