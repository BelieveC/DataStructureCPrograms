#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
}typedef node;

void newnode(node* root,int val)
{
    while(root->next!=NULL){
        root = root->next;
    }
    root->next = (node*)malloc(sizeof(node));
    root->next->value = val;
    root->next->next = NULL;
}
void print(node* root)
{
    while(root->next!=NULL){
        printf("%d ",root->next->value);
        root = root->next;
    }
}
void rem(node* root)
{
    while(root->next!=NULL && root->next->next!=NULL){
        node* prev = root;
        root = root->next;
        if(root->value < root->next->value){
            prev->next = root->next;
            root = prev;
        }
    }
}
int main()
{
    node* root = (node*)malloc(sizeof(node));
    root->next = NULL;
    newnode(root,2);
    newnode(root,3);
    newnode(root,5);
    newnode(root,1);
    print(root);
    rem(root);
    printf("\n");
    print(root);
    return 0;
}
