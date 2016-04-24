#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct node{
    int key;
    int value;
    struct node* next;
}typedef node;
void newnode(node* root,int val,int k)
{
    while(root->next!=NULL){
        root = root->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->value = val;
    temp->key = k;
    root->next = temp;
}
void insert(node* hashtable[],int val,int k)
{
    int temp = k%SIZE;
    printf("I am here %p\n",hashtable[temp]);
    newnode(hashtable[temp],val,k);

}
int main()
{
    node* hashtable[SIZE];
    int i;
    for(i=0;i<SIZE;i++){
        hashtable[i] = (node*)malloc(sizeof(node));
        hashtable[i]->next = NULL;
    }
    insert(123,hashtable,23);
    insert(232,hashtable,32);

    return 0;
}
