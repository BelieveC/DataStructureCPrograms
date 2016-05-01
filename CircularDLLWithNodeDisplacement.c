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
node* rot(node* root,int k)
{
    node* newhead = root->next;
    node* head = root;
    head->last->next = head->next;
    head->next->last = head->last;
    head = head->next;
    int i=1;
    for(i;i<=k;i++){
        head = head->next;
    }
    head->next->last = root;
    root->next = head->next->last;
    head->next = root;
    root->last = head;
    return newhead;
}
int main()
{
    node* root = NULL;
    root = newnode(root,3);
    root = newnode(root,4);
    root = newnode(root,6);
    root = rot(root,1);
    printf("%d\n",root->value);
    printf("%d\n",root->next->value);
    printf("%d\n",root->next->next->value);
    return 0;
}
