#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left,*right,*parent;
}typedef node;
node* newnode(int data)
{
    node* temp = (node*)malloc(sizeof(node));\
    temp->left = NULL;
    temp->right = NULL;
    temp->value =data;
    return temp;
}
node* insert(node* root,int data)
{
    if(root==NULL){
        root = newnode(data);
    }
    else if(root->value>= data){
        root->left = insert(root->left,data);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right,data);
        root->right->parent = root;
    }
    return root;
}
void dis(int key1,int key2,node* root,int* count)
{
    if(key1>key2){
        int temp = key1;
        key1 = key2;
        key2 = temp;
    }
    while(!(key1<=root->value && key2>root->value)){
         if(key1<root->value && key2<root->value){
            root = root->left;
        }
        else if(key1>root->value && key2>root->value){
            root = root->right;
        }
    }
    node* rootdup = root;
    *count = *count + 2;
    root = root->left;
    while(root->value!=key1){
       if(root->value>=key1){
        root =root->left;
        }
        else{
            root = root->right;
        }
        *count = *count+1;
    }
    rootdup = rootdup->right;
    while(rootdup->value!=key2){
        if(rootdup->value>=key2){
            rootdup = rootdup->left;
        }
        else{
            rootdup = rootdup->right;
        }
        *count = *count + 1;
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
    insert(root,2);
    insert(root,9);
    int count = 0;
    dis(2,52,root,&count);
    printf("%d",count);
    return 0;
}

