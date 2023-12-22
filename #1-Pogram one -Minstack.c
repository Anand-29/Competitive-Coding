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
int pop(){
  if(stack[top]<min){
    min=2*min-stack[top--];
     return min;
 }
 else{
   return stack[top--];
 }
}
 void display(){
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
         while(1){
             printf("Enter your choice:-\n");
             printf("press 1 to push:-\n");
             printf("press 2 to pop:-\n");
             printf("press 3 to display:-\n");
             printf("press 4 to display minimum value:-\n");
             printf("press 5 to exit:-");
             int s;
             scanf("%d",&s);
             switch(s){
                 case 1: printf("enter the number to be inserted:-\n");
                 scanf("%d",&s);
                 push(s);
                 printf("value %d is inserted:-\n",s);
                 break;
                 case 2: 
                 printf("value %d is deleted:-\n",pop());
                 break;
                 case 3:
                 printf("satck elements are:-\n");
                 display();
                 break;
                 case 4:
                 printf("the minimum valur is %d",min);
                 break;
                 case 5: return 0;
                 
             }
         }
       
     }
