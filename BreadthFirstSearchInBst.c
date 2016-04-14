#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node{
    int value;
    struct node* left,*right;
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
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}
int is_empty(int front,int rear)
{
    if(front==-1 && rear == -1){
        return 1;
    }
    return 0;
}
int is_full(int front,int rear)
{
    if((rear+1)%SIZE==front){
        return 1;
    }
    return 0;
}

void enqueue(node* a[],node* value,int*front,int*rear)
{
    if(!is_full(*front,*rear)){
        if(is_empty(*front,*rear)){
            *front = 0;
            *rear = 0;
            a[*front] = value;
        }
        else{
            *rear = (*rear+1)%SIZE;
            a[*rear] = value;
        }
    }
}

node* dequeue(node* a[],int* front,int*rear)
{
    node* m;
    if(!is_empty(*front,*rear)){
        if(*front == *rear){
            m = a[*front];
            *front = -1;
            *rear = -1;
        }
        else{
             m = a[*front];
            *front = (*front+1)%SIZE;
        }
        return m;
    }
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
    node* a[SIZE];
    int front = -1,rear = -1;
    node* root = newnode(2);
    insert(root,4);
    insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,10);
    insert(root,7);
    enqueue(a,root,&front,&rear);
    while(!is_empty(front,rear)){
        node* temp = dequeue(a,&front,&rear);
        if(temp->left!=NULL){
            enqueue(a,temp->left,&front,&rear);
        }
        if(temp->right!=NULL){
            enqueue(a,temp->right,&front,&rear);
        }
        printf("%d\n",temp->value);
    }
    return 0;
}
