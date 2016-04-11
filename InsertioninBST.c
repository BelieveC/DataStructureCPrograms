#include<stdio.h>
struct node{
    int value;
    struct node*left,*right;
}typedef node;
node* newnode(int x)
{
    node*temp = (node*)malloc(sizeof(node));
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
    }
    else{
        root->right = insert(root->right,x);
    }
    return root;

}
void print(node* root)
{
    if(root!=NULL){
        print(root->left);
        printf("%d\n",root->value);
        print(root->right);
    }
}
int main()
{
    node *root = (node*)malloc(sizeof(node));
    root->value= 5;
    root->left = NULL;
    root->right = NULL;
    insert(root,2);
    insert(root,4);
    insert(root,6);
    print(root);
    return 0;
}
