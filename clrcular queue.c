#include<stdio.h>
int f=-1,r=-1,n=3;
int a[3];
void en(int d){
    if(f==-1){
        f=0;
        a[++r]=d;
    }
    else if(r>=n-1 || r+1==f){
        if(f>0 && r>=n-1){
            r=-1;
            a[++r]=d;
        }
        else{
                printf("queue is full");
            }
        }
    else{
        a[++r]=d;
    }
     printf(" after %d  %d \n",f,r);
}
void de(){
     printf(" before %d  %d \n",f,r);
    if(f==-1 || f>r){
        if(r>=0 && f>=n-1){
            f=0;
        }
        else{
        f++;
        }
    }
    else if(f<r){
        f++;
    }
    else{
        f=-1;
        r=-1;
        printf("empty");
    }
    
   printf(" after %d  %d \n",f,r);
}
void display(){
    if(f<=r){
    for(int i=f;i<=r;i++){
        printf("%d ",a[i]);
    }
    }
    else{
        for(int i=f;i<n;i++){
            printf("%d ",a[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",a[i]);
        }
    }
   
}
int main(){
    en(10);
    display();
    en(20);
    display();
    en(30);
    display();
    de();
    display();
    en(50);
    display();
    en(60);
    display();
    de();
    display();
    de();
    display();
    de();
    display();
    
}
