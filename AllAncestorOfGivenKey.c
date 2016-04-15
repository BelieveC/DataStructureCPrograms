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
    else if(root->value>= data){
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
        return root;
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
int allances(node* root,node* ances[],int data)
{
    node* current = search(root,data);
    int count = 0;
    node* ancestor = root;
    while(ancestor!=current){
        if(ancestor->value>= data){
            ances[count] = ancestor;
            ++count;
            ancestor = ancestor->left;
        }
        else{
            ances[count] = ancestor;
            count++;
            ancestor = ancestor->right;
        }
    }
    return count;
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
    node* ances[100];
    int count = allances(root,ances,100);
    int i;
    for(i=0;i<count;i++){
        printf("%d\n",ances[i]->value);
    }
    return 0;
}
