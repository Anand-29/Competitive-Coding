#include <stdio.h>
int stack[10];
int top=-1,min=0;
void push(int d){
if (top==-1){
  stack[++top]=d;
  min=d;
}
else if(d>stack[top]){
  stack[++top]=d;
}
else if(d<=stack[top]){
  stack[++top]=2*d-min;
  min=d;
}
}
void pop(){
  if(stack[top]<min){
    min=2*min-stack[top];
      top--;
 }
 else{
   top--;
 }
}
 void display(){
   printf("\n");
   int t=min;
   for(int i=top;i>=0;i--){
     if(stack[i]>min){
       printf("%d ",stack[i]);
     }
       else
       {
         printf("%d ",t);
         t=t*2-stack[i];
       }
     }
 }
     
     int main(){
       push(5);
       push(3);
       display();
       printf("\n%d",min);
       push(1);
       printf("\n%d",min);
       pop();
       printf("\n%d",min);
       
     }
   
 
