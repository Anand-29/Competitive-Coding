#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *root,int value){
    if(root==NULL){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(root->data>value){
        root->left=insert(root->left,value);
    }
    if(root->data<value){
        root->right=insert(root->right,value);
    }
    return root;
}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
     printf("%d ",root->data);
}
void minimum(struct node *root){
    if(root->left==NULL){
        printf("%d\n",root->data);
        return;
    }
    minimum(root->left);
}
void maximum(struct node *root){
    if(root->right==NULL){
        printf("%d\n",root->data);
        return;
    }
    maximum(root->right);
}
void leftborder(struct node *root){
   if(root==NULL){
        return;
    }
    if(root->left!=NULL){
    printf("%d",root->data);
    leftborder(root->left);
    }
    else if(root->right!=NULL){
        printf("%d",root->data);
        leftborder(root->right);
    }
}
void rightborder(struct node *root){
    if(root==NULL){
        return;
    }
    if(root->right!=NULL){
    rightborder(root->right);
    printf("%d",root->data);
    }
    else if(root->left!=NULL){
        rightborder(root->left);
        printf("%d",root->data);
    }
}
void leafnodes(struct node *root){
    if(root==NULL){
        return;
    }
    leafnodes(root->left);
    if(root->left==NULL && root->right==NULL){
        printf("%d",root->data);
    }
    leafnodes(root->right);
    
}
int  height(struct node *root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
    
}
int main(){
    root=insert(root,10);
    insert(root,5);
    insert(root,12);
    insert(root,2);
    insert(root,30);
    insert(root,3);
//    preorder(root);
   // printf("\n");
 //   inorder(root);
    printf("\n");
//   postorder(root);
    printf("\n");
  //  minimum(root);
 //   maximum(root);
//    leftborder(root);
    printf("\n");
  // rightborder(root);
    printf("\n");
   // leafnodes(root);
    printf("\n");
    printf("%d",height(root));
    }
