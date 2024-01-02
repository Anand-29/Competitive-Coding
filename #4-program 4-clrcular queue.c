#include<stdio.h>
#define size 5
int front=-1,rear=-1;
int queue[size];
void enqueue(int data){
    if(front==-1){
        front=0;
        queue[++rear]=data;
    }
    else if(rear>=size-1 || rear+1==front){
        if(front>0 && rear>=size-1){
            rear=-1;
            queue[++rear]=data;
        }
        else{
                printf("queue is full\n");
            }
        }
    else{
        queue[++rear]=data;
    }
}
void dequeue(){
    if(front==-1 || front>rear){
        if(rear>=0 && front>=size-1){
            front=0;
        }
        else{
        front++;
        }
    }
    else if(front<rear){
        front++;
    }
    else{
        front=-1;
        rear=-1;
        printf("empty\n");
    }
}
void display(){
    if(front<=rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    }
    else{
        for(int i=front;i<size;i++){
            printf("%d ",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}
int main(){
    while(1){
        printf("press 1 to enqueue data\n");
        printf("press 2 to dequeue data\n");
        printf("press 3 to display queue elements\n");
        printf("press 4 to display front element\n");
        printf("press 5 to display rear element\n");
        printf("press 6 to exit\n");
        int a;
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("enter the data\n");
            scanf("%d",&a);
            enqueue(a);
            break;
            case 2:
            printf("%d is dequeued\n",queue[front]);
            dequeue();
            break;
            case 3:
            printf("the elements in queue are\n");
            display();
            break;
            case 4:
            printf("the front element is %d \n",queue[front]);
            break;
            case 5:
            printf("the rear element is %d \n",queue[rear]);
            break;
            case 6:
            return 0;
        }
    }
}
