#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void insert_end(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
         temp->next=newnode;
    newnode->prev=temp;
    }
}
void insert_begining(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}
void print(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertmiddle(int value,int pos){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    struct node *temp1=head;
    struct node *temp2=temp1->next;
    if(pos-1>1){
        temp1=temp1->next;
        temp2=temp2->next;
        pos--;
    }
    temp1->next=newnode;
    newnode->next=temp2;
    newnode->prev=temp1;
    temp2->prev=newnode;
}
void delete_end(){
    struct node *temp1=head;
    struct node *temp2=temp1->next;
    while(temp2->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=NULL;
    free(temp2);
}
void delete_begining(){
    struct node *temp1=head;
    struct node *temp2=temp1->next;
    temp2->prev=NULL;
    head=temp2;
    free(temp1);
}
void delete_middle(int pos){
    struct node *temp1=head;
    struct node *temp2=temp1->next;
    while(pos-1>1){
        temp1=temp1->next;
        temp2=temp2->next;
        pos--;
    }
    temp1->next=temp2->next;
    struct node *temp3=temp2->next;
    temp3->prev=temp2;
    free(temp2);
}
int main(){
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);
    print();
    insert_begining(45);
    print();
    int pos=3;
    insertmiddle(5,pos);
    print();
    delete_end();
    print();
    delete_begining();
    print();
    pos=4;
    delete_middle(pos);
    print();
}
