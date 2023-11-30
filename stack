#include <stdio.h>
int stack[10];
int top=-1;
void push(int d){
  stack[++top]=d;
}
void pop() {
  top--;
}
void display(){
  int t=top;
  for(int i=t; i>=0;i--) {
    printf("%d\n",stack[i]);
   
  }
}
void max(){
  int max=stack[top];
  for (int i=top-1;i>=0;i--){
    if(stack[i]>max){
      max=stack[i];
    }
  }
   printf("%d\n",max);
}
void min(){
  int m=stack[top];
  for (int i=top-1;i>=0;i--){
    if(stack[i]<m){
      m=stack[i];
    }
  }
  printf("%d\n",m);
}
int main() { 
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
   display();
    max();
    min();
}
