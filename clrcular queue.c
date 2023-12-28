#include<stdio.h>
int f=-1,r=-1,n=3;
int a[3];
void en(int d){
    printf(" before %d  %d \n",f,r);
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
                printf("full");
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
        if(r>0 && r<f){
            f=0;
        }
        f++;
    }
    else if(f<r){
        f++;
    }
    else{
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
   
}
int main(){
    en(10);
    en(10);
    en(10);
    en(10);
    de();
    en(10);
   // en(10);
    
    
}
