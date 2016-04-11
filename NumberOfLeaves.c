#include<stdio.h>
struct node{
    int value;
    struct node* right,*left,*parent;
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
    else if(root->value>=data){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }

}
void print(node* root)
{
    if(root!=NULL){
        print(root->left);
        printf("Value = %d\n ",root->value);
        print(root->right);
    }
}

void numofleaf(node* root,int* count)
{
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        *count = *count + 1;
    }
    numofleaf(root->left,count);
    numofleaf(root->right,count);
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
    int count =0;
    numofleaf(root,&count);
    printf("%d",count);
    return 0;
}
