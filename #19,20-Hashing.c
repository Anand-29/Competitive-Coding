#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
struct node{
    int data;
    struct node *next;
};
int hash(int d){
    int c=0,n=d*d;
    while(n>0){
        c++;
        n=n/10;
    }
    if(c%2==1){
        return ((d*d)/(int)pow(10,(c/2))%10);
    }
    else{
        int a=((d*d)/(int)pow(10,(c/2))%10);
        int b=((d*d)/(int)pow(10,(c/2)-1)%10);
        return a*10+b;
    }
}
struct node *newnode(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    return nn;
}
void insert(struct node **arr,int d){
    int key=hash(d);
    if(*(arr+key)==NULL){
        *(arr+key)=newnode(d);
    }
    else{
        struct node *t=*(arr+key);
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=newnode(d);
    }
}
int search(struct node **arr,int d){
    int key=hash(d);
    struct node *t=*(arr+key);
    if(t==NULL){
        return 0;
    }
    else{
        while(t!=NULL){
            if(t->data==d){
                return 1;
            }
        t=t->next;
    }
    }
}
void print(struct node **arr){
    for(int i=0;i<=MAX;i++){
        struct node *t=*(arr+i);
        while(t!=NULL){
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
void delete(struct node **arr,int d){
    int key=hash(d);
    struct node *t1=*(arr+key);
    struct node *t2=t1->next;
    if(t1->data==d){
        *(arr+key)=t2;
        free(t1);
    }
    else{
        while(t2!=NULL){
            if(t2->data==d){
                t1->next=t2->next;
                free(t2);
            }
            t1=t1->next;
            t2=t2->next;
        }
    }
}
int main(){
    struct node **arr=(struct node **)malloc(sizeof(struct node));
    while(1){
    printf("Press 1 to insert the data\n");
    printf("press 2 to search the data\n");
    printf("Press 3 to print the data in the table\n");
    printf("Press 4 to delete the data\n");
    printf("press 5 to exit\n");
    int a;
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("enter the data\n");
        scanf("%d",&a);
        insert(arr,a);
        break;
        case 2:
        printf("enter the search element\n");
        scanf("%d",&a);
        if(search(arr,a)==1){
            printf(" %d is present\n",a);
        }
        else{
            printf(" %d is not present\n",a);
        }
        break;
        case 3:
        print(arr);
        break;
        case 4:
        printf("enter the data to be deleted\n");
        scanf("%d",&a);
        delete(arr,a);
        printf(" %d is deleted",a);
        break;
        case 5:
        return 0;
}
}
}
