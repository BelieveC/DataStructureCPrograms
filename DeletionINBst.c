#include<stdio.h>
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
    else{
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}

void print(node* root)
{
    if(root!=NULL){
        print(root->left);
        printf("Value = %d\n with Address = %p and Parent = %p\n",root->value,root,root->parent);
        print(root->right);
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
    else if(root->value >= data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}
node* max(node* root)
{
    while(root->right!=NULL){
            printf("I am here!\n");
        root = root->right;
    }
    return root;
}
node* min(node* root)
{
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
int left(node* root)
{
    if(root->parent->value>=root->value){
        return 1;
    }
    return 0;
}
void delete(node* root,int data)
{
    node* pos = search(root,data);
    if(pos->left == NULL && pos->right == NULL){
        if(pos->parent->value>=data){
            pos->parent->left = NULL;
        }
        else{
            pos->parent->right = NULL;
        }
    }
    else if(pos->left==NULL && pos->right!= NULL || pos->right==NULL && pos->left!= NULL){
        if(pos->left==NULL && pos->right!= NULL){
           if(left(pos)){
                pos->parent->left = pos->right;
                 pos->right->parent = pos->parent;
        }
        else{
            pos->parent->right = pos->right;
             pos->right->parent = pos->parent;
            }
        }
        else{
            if(left(pos)){
                pos->parent->left =pos->left;
                pos->left->parent = pos->parent;
            }
            else{
                pos->parent->right = pos->left;
                pos->left->parent = pos->parent;
            }
        }
    }
    else{
        node* maximum =max(pos->left);
        pos->value = maximum->value;
        delete(pos->left,maximum->value);
    }
}
int main()
{
    node* root = (node*)malloc(sizeof(node));
    root = newnode(4);
    root->parent = root;
    insert(root,7);
    insert(root,8);
    insert(root,9);
    insert(root,3);

    print(root);
    delete(root,7);
    print(root);


    return 0;
}
