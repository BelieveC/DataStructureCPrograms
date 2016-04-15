#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right;
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
node* max(node* root)
{
    if(root->right!=NULL){
        max(root->right);
    }
    else{
        return root;
    }
}

node* predecessor(node* root,int data)
{
    node* current = search(root,data);
    if(current->left!=NULL){
        return max(current->left);
    }
    else{
        node* predecessor = NULL;
        node* ancestor = root;
        while(ancestor!=current){
            if(ancestor->value<data){
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else{
                ancestor = ancestor->left;
            }
        }
        return predecessor;
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
    node* pred = predecessor(root,52);
    printf("%d\n",pred->value);
    return 0;
}
