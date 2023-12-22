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
        printf("%d",root->data);
        return;
    }
    minimum(root->left);
}
void maximum(struct node *root){
    if(root->right==NULL){
        printf("%d",root->data);
        return;
    }
    maximum(root->right);
}
void leftborder(struct node *root){
   if(root==NULL){
        return;
    }
    if(root->left!=NULL){
    printf("%d ",root->data);
    leftborder(root->left);
    }
    else if(root->right!=NULL){
        printf("%d ",root->data);
        leftborder(root->right);
    }
}
void rightborder(struct node *root){
    if(root==NULL){
        return;
    }
    if(root->right!=NULL){
    rightborder(root->right);
    printf("%d ",root->data);
    }
    else if(root->left!=NULL){
        rightborder(root->left);
        printf("%d ",root->data);
    }
}
void leafnodes(struct node *root){
    if(root==NULL){
        return;
    }
    leafnodes(root->left);
    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
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
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int isBSTUtil(struct node* node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return isBSTUtil(node->left, min, node->data - 1)
           &&
           isBSTUtil(node->right, node->data + 1,
           max);
}
void levelorder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
int isBST(struct node* node)
{
    return (isBSTUtil(node, -1000, 1000));
}

int main(){
    printf("insert the root data:-\n");
    int a;
    scanf("%d",&a);
    printf("root data %d inserted:-\n",a);
    while(1){
        printf("press 1 to insert data:- \n");
        printf("press 2 to print preorder traversal:- \n");
        printf("press 3 to print inorder traversal:- \n");
        printf("press 4 to print postorder traversal:- \n");
        printf("press 5 to print minimum element:- \n");
        printf("press 6 to print maximum element:- \n");
        printf("press 7 to print leftborder:- \n");
        printf("press 8 to print right border:- \n");
        printf("press 9 to print leafnodes:- \n");
        printf("press 10 to print height of the tree:-\n");
        printf("press 11 to print level order traversal:- \n");
        printf("press 12 to validate BST or not:- \n");
        printf("press 13 to exit:- \n");
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("enter the element to be inserted:-\n");
            root=insert(root,a);
            printf("%d is inserted\n",a);
            break;
            case 2:
            printf("preorder:- ");
            preorder(root);
            printf("\n");
            break;
            case 3:
            printf("inorder:- ");
            inorder(root);
            printf("\n");
            break;
            case 4:
            printf("postorder:- ");
            postorder(root);
            printf("\n");
            break;
            case 5:
            printf("minimum data:- ");
            minimum(root);
            printf("\n");
            break;
            case 6:
            printf("maximum data:- ");
            maximum(root);
            printf("\n");
            break;
            case 7:
            printf("left border:- ");
            leftborder(root);
            printf("\n");
            break;
            case 8:
            printf("right border:- ");
            rightborder(root);
            printf("\n");
            break;
            case 9:
            printf("leaf nodes:- ");
            leafnodes(root);
            printf("\n");
            break;
            case 10:
            printf("height of the tree %d \n",height(0));
            break;
            case 11:
            printf("level order:- ");
            levelorder(root);
            printf("\n");
            break;
            case 12:
            if(isBST(root)==1){
                printf("vaild BST\n");
            }
            else{
                printf("not a BST");
            }
            case 13:
            return 0;
            break;
        }
    }
}
