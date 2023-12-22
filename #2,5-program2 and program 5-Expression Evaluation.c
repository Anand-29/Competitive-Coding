#include<stdio.h>
char stack[100];
int top=-1;
char s[100];
int t=-1;
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
void empty(){
        for(int i=top;i>=0;i--){
            s[++t]=stack[i];
        }
        top=-1;
    }
void display(){
    printf("solution:- ");
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}
int main(){
    char a[50];
    printf("enter the expression\n");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]>=48 && a[i]<=58){
            s[++t]=a[i];
        }
        else{
            switch(a[i]){
                case '+':
                        if(top!=-1 && precedence(stack[top])>precedence(a[i])){
                        s[++t]=pop();
                        }
                        push(a[i]);
                        break;
                case '-': 
                        if(top!=-1 && precedence(stack[top])>precedence(a[i])){
                        s[++t]=pop();
                        }
                        push(a[i]);
                        break;
                case '/': 
                        if(top!=-1 && precedence(stack[top])>precedence(a[i])){
                        s[++t]=pop();
                        }
                        push(a[i]);
                        break;
                case '*': 
                        if(top!=-1 && precedence(stack[top])>precedence(a[i])){
                        s[++t]=pop();
                        }
                        push(a[i]);
                        break;
                case '(': 
                        push(a[i]);
                        break;
                case ')': 
                        if(stack[top]!='('){
                        s[++t]=pop();
                        }
                        pop();
                        break;
                case '^': 
                        if(top!=-1 && precedence(stack[top])>=precedence(a[i])){
                        s[++t]=pop();
                        }
                        push(a[i]);
                        break;   
            }
        }
    }
    empty();
    printf("postfix of %s is %s\n",a,s);
    //EVALUATE THE EXPRESSION:-
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0' && s[i]<='9'){
            push(s[i]);
        }
        else{
            int v1=(int)(pop()-'0');
            int v2=(int)(pop()-'0');
            switch(s[i]){
                case '+':
                push((char)(v1+v2+'0'));
                break;
                case '*':
                push(v1*v2);
                break;
                case '-':
                push((char)(v1-v2+'0'));
                break;
                case '/':
                push((char)(v1/v2+'0'));
                break;
            }
        }
    }
    display();
}
