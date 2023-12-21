//given two binary tree check whether mirrored or not:-

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *left,*right;
};
int mirror(struct node *root1,struct node *root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        return root1->data==root2->data && mirror(root1->left,root2->right) && mirror(root1->right,root2->left);
    }
}
struct node * newnode(int d){
    struct node *nn=malloc(sizeof(struct node));
    nn->data=d;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
int main(){
    struct node *root1=newnode(1);
    struct node *root2=newnode(1);
    root1->left=newnode(2);
    root1->right=newnode(3);
    root1->left->left=newnode(4);
    root1->left->right=newnode(5);
    
    root2->left=newnode(3);
    root2->right=newnode(2);
    root2->right->left=newnode(5);
    root2->right->right=newnode(4);
    
    if(mirror(root1,root2)==true)
        printf("mirrored");
    else
        printf("not mirrored");
    
}
