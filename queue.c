#include<stdio.h>
int q[10];
int f=-1,r=-1;
void enqueue(int d){
    if(r>9){
        printf("\nover flow");
    }
    if(r==-1){
        q[++r]=d;
        f++;
    }
    else{
        q[++r]=d;
    }
}
void dequeue(){
    if(f>r && r==-1){
        printf("\nunderflow");
    }
    else{
    printf("\ndeleted%d",q[f++]);
    }
}
void display(){
    for(int i=f;i<=r;i++){
        printf("\nelement%d",q[i]);
    }
}
void min_and_max(){
    int min=q[f];
    int max=q[f];
    for(int i=f+1;i<=r;i++){
        if(min>q[i]){
            min=q[i];
        }
        else{
            max=q[i];
        }
    }
    printf("\nminimum%d\nmaximu%d",min,max);
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    min_and_max();
}
