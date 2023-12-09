#include<stdio.h>
int stack[100];
int top=-1;
void push(char d){
    stack[++top]=d;
}
int  pop(){
    return stack[top--];
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}
int main(){
    char a[50];
    printf("enter the string");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]>=48 && a[i]<=58){
            push((int)a[i]-48);
        }
        else{
            //printf("%d",top);
            int v1=pop();
            int v2=pop();
            switch(a[i]){
                case '+':
                        push(v1+v2);
                        break;
                case '-':
                        push(v2-v1);
                        break;
                case '/':
                        push(v2/v1);
                        break;
                case '*':
                        push(v2*v1);
                        break;
            }
        }
    }
    
   display();
}
