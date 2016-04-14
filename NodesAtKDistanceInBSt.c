#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right,*parent;
}typedef node;

node* newnode(int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root,int x)
{
    if(root==NULL){
        root = newnode(x);
    }
    else if(root->value>=x){
        root->left = insert(root->left,x);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right,x);
        root->right->parent = root;
    }
    return root;

}
void printk(node* root,int k,int count)
{
    if(root!=NULL)
    {
        if(count==k){
            printf("%d\n",root->value);
        }
        if(count<k){
                count++;
            printk(root->left,k,count);
            printk(root->right,k,count);
        }
        else{
            return;
        }
    }
}
int main()
{
    node* root =newnode(2);
    insert(root,1);
    insert(root,4);
    insert(root,3);
    insert(root,5);
    insert(root,6);
     printk(root,2,0);

    return 0;
}
