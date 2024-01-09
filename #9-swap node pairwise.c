#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head;
void insert(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    if(head==NULL){
    head=nn;
    nn->prev=NULL;
    }
    else{
        struct node *t=head;
        while(t->next!=NULL)
        t=t->next;
        t->next=nn;
        nn->prev=t;
    }
}
void swap(int *a,int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void swap_node_pairwise(){
    struct node *t=head;
    while(t->next!=NULL){
    swap(&t->data,&t->next->data);
    t=t->next->next;
    }
}
void display(){
    struct node *t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}
int main(){
    head=NULL;
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);
    swap_node_pairwise();
    display();
}
