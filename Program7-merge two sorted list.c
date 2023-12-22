#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head1,*head2,*head3;
void insert1(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    if(head1==NULL)
    head1=nn;
    else{
        struct node *t=head1;
        while(t->next!=NULL)
        t=t->next;
        t->next=nn;
    }
}
void insert2(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    if(head2==NULL)
    head2=nn;
    else{
        struct node *t=head2;
        while(t->next!=NULL)
        t=t->next;
        t->next=nn;
    }
}
void insert3(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    if(head3==NULL)
    head3=nn;
    else{
        struct node *t=head3;
        while(t->next!=NULL)
        t=t->next;
        t->next=nn;
    }
}
void mergetwolist(){
    struct node *t1=head1;
    struct node *t2=head2;
    while(t1!=NULL && t2!=NULL){
        if(t1->data<=t2->data){
            insert3(t1->data);
            t1=t1->next;
        }
       else{
            insert3(t2->data);
            t2=t2->next;
        }  
    }
    while(t1!=NULL){
        insert3(t1->data);
        t1=t1->next;
    }
    while(t2!=NULL){
        insert3(t2->data);
        t2=t2->next;
    }
}
void display(){
    struct node *t=head3;
    while(t!=NULL){
        printf("%d " ,t->data);
        t=t->next;
    }
}
int main(){
    head1=NULL,head2=NULL,head3=NULL;
    insert1(10);
    insert1(11);
    insert1(12);
    insert1(13);
    insert1(14);
    insert2(15);
    insert2(16);
    insert2(17);
    insert2(18);
    insert2(19);
    mergetwolist();
    display();
}
