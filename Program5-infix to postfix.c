#include<stdio.h>
char stack[100];
int top=-1;
int precedence(char ch){
    switch(ch){
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}
void push(char d){
    stack[++top]=d;
}
char pop(){
    return stack[top--];
}
void display(){
        for(int i=top;i>=0;i--){
            printf("%c",stack[i]);
        }
    }
int main(){
    char a[50];
    printf("enter the string\n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]>=48 && a[i]<=58){
            printf("%c",a[i]);
        }
        else{
            switch(a[i]){
                case '+':
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        printf("%c",pop());
                        }
                        push(a[i]);
                        break;
                case '-': 
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        printf("%c",pop());
                        }
                        push(a[i]);
                        break;
                case '/': 
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        printf("%c",pop());
                        }
                        push(a[i]);
                        break;
                case '*': 
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        printf("%c",pop());
                        }
                        push(a[i]);
                        break;
                case '(': 
                        push(a[i]);
                        break;
                case ')': 
                        if(stack[top]!='('){
                        printf("%c",pop());
                        pop();
                        }
                        break;
                case '^': 
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        printf("%c",pop());
                        }
                        push(a[i]);
                        break;   
            }
        }
    }
    display();
}
