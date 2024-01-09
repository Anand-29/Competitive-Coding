#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head1,*head2,*head3;
struct node *newnode(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    return nn;
}
void insert(int d,struct node *head){
    if(head==NULL)
    head=newnode(d);
    else{
        struct node *t=head1;
        while(t->next!=NULL){
        t=t->next;
        }
        t->next=newnode(d);
    }
}
void mergetwolist(struct node *t1,struct node *t2){
    while(t1!=NULL && t2!=NULL){
        if(t1->data<=t2->data){
            insert(t1->data,head3);
            t1=t1->next;
        }
       else{
            insert(t2->data,head3);
            t2=t2->next;
        }  
    }
    while(t1!=NULL){
        insert(t1->data,head3);
        t1=t1->next;
    }
    while(t2!=NULL){
        insert(t2->data,head3);
        t2=t2->next;
    }
}
void display(struct node *t){
    while(t!=NULL){
        printf("%d " ,t->data);
        t=t->next;
    }
}
int main(){
    head1=NULL,head2=NULL,head3=NULL;
    while(1){
        printf("press 1 to enter the data in head1\n");
        printf("press 2 to enter the data in head2\n");
        printf("press 3 to merge the lists\n");
        printf("press 4 to display the merged list\n");
        int a;
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("Enter the data\n");
            scanf("%d",&a);
            insert(a,head1);
            break;
            case 2:
            printf("enter the data\n");
            scanf("%d",&a);
            insert(a,head2);
            break;
            case 3:
            printf("elements merged\n");
            mergetwolist(head1,head2);
            break;
            case 4:
            printf("the merged list is\n");
            display(head3);
            break;
            case 5:
            return 0;
        }
    }
    
}
