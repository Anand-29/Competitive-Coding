#include<stdio.h>
#define max 10
int hash(int d){
    return d%max;
}
void insert(int table[],int d){
    int k=hash(d);
    if(table[k]!=0){
        //linear probe
        for(int i=k+1;i<max;i++){
            if(table[i]==0){
                table[i]=d;
                break;
            }
        }
    }
    else{
        table[k]=d;
    }
}
void search(int table[],int d){
    int k=hash(d);
    if(table[k]!=d){
        //linear probe
        for(int i=k+1;i<max;i++){
            if(table[i]==d){
                printf("search element %d is present\n",table[i]);
                break;
            }
        }
    }
    else if(table[k]==d){
        printf("search element %d is present\n",table[k]);
                
    }
    else{
        printf("data is not present\n");
    }
}
void delete(int table[],int d){
    int k=hash(d);
    if(table[k]!=d){
        //linear probe
        for(int i=k+1;i<max;i++){
            if(table[i]==d){
                table[i]=0;
                printf("data is deleted\n");
                break;
            }
        }
    }
    else if(table[k]==d){
        table[k]=0;
        printf("data is deleted\n");
    }
    else{
        printf("data is not present\n");
    }
}
void print(int table[]){
    printf("the table elements are\n");
    for(int i=0;i<max;i++){
        if(table[i]!=0){
        printf("%d",table[i]);
        }
    }
}
int main(){
    int table[max];
    for(int i=0;i<max;i++){
        table[i]=0;
    }
    while(1){
        printf("press 1 to insert the data\n");
        printf("press 2 to search the data\n");
        printf("press 3 to delete the data\n");
        printf("press 4 to display the data\n");
        printf("press 5 to exit");
        int a;
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("enter the data\n");
            scanf("%d",&a);
            insert(table,a);
            break;
            case 2:
            printf("enter thr search element\n");
            scanf("%d",&a);
            search(table,a);
            break;
            case 3:
            printf("enter the data\n");
            scanf("%d",&a);
            delete(table,a);
            break;
            case 4:
            print(table);
            break;
            case 5:
            return 0;
        }
        
    }
}
