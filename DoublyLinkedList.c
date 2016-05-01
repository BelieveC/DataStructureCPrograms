#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next,*last;
}typedef node;

node* newnode(node* root,int val)
{
    if(root==NULL){
        root = (node*)malloc(sizeof(node));
        root->value = val;
        root->next = root;
        root->last = root;
    }
    else{
        node* head = root;
        while(head->next!=root){
            head = head->next;
        }
        head->next = (node*)malloc(sizeof(node));
        head->next->value = val;
        head->next->next = root;
        head->next->last = head;
        root->last = head->next;
    }
    return root;
}
int main()
{
    node* root = NULL;
    root = newnode(root,2);
    root = newnode(root,3);
    return 0;
}


