#include<stdio.h>
int a[100];
int top=-1;
int min;
void push(int d){
    if(top==-1){
        a[++top]=d;
        min=d;
    }
    else if(d>min){
        a[++top]=d;
    }
    else{
        a[++top]=(2*d-min);
        min=d;
    }
}
void pop(){
    if(a[top]<min){
        min=2*a[top]-min;
    }
    top--;
}
int peek(){
    if(a[top]<min){
        return min;
    }
    else{
        return a[top];
    }
}
int mini(){
    return min;
}
int main(){
    push(10);
    push(2);
    push(10);
    push(-1);
    push(34);
    pop();
    push(5);
    printf("%d\n",peek());
    printf("%d\n",mini());
}
