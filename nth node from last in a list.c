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
void nth_node_from_last(int pos){
    struct node *t=head;
    while(t->next!=NULL)
    t=t->next;
    while(pos>1){
    t=t->prev;
    pos--;
    }
    printf("nth node from last %d",t->data);
}
int main(){
    head=NULL;
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    int a;
    printf("enter the data\n");
    scanf("%d",&a);
    nth_node_from_last(a);
}
