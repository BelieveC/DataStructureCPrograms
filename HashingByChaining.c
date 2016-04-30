#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
    int key;
    int value;
    struct node* next;
}typedef node;

void newnode(node* root,int val)
{
    while(root->next!=NULL){
        root = root->next;
    }
    root->next = (node*)malloc(sizeof(node));
    root->next->next = NULL;
    root->value = val;
}
int hashfx(int value)
{
    return value%20;
}

void insert(node* hashtable[],int val)
{
    int x = hashfx(val);
    newnode(hashtable[x],val);
}
void check(node* hashtable[],int val)
{
    int x = hashfx(val);
    while(hashtable[x]->next!=NULL){
        if(hashtable[x]->value == val){
            printf("Value is present\n");
            break;
        }
        hashtable[x] = hashtable[x]->next;
    }
}
int main()
{
    node* hashtable[20];
    int i;
    for(i=0;i<20;i++)
    {
        hashtable[i] = (node*)malloc(sizeof(node));
        hashtable[i]->next = NULL;
        hashtable[i]->value = INT_MAX;
    }
    insert(hashtable,2);
    insert(hashtable,3);
    check(hashtable,10);
    return 0;
}
