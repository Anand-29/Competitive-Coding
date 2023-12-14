import java.util.*;
class Main{
    class Node{
        int data;
        Node left;
        Node right;
        Node(int d){
            data=d;
            left=null;
            right=null;
        }
    }
    Node root=null;
    Node insert(Node root,int d){
        if(root==null){
            Node newnode=new Node(d);
            return newnode;
        }
        else if(root.data>d){
            root.left=insert(root.left,d);
        }
        else if(root.data<d){
            root.right=insert(root.right,d);
        }
        return root;
    }
    void display(Node root){
        if(root==null)
        return;
        display(root.left);
        display(root.right);
        System.out.print(root.data);
    }
    public static void main(String a[]){
        Main l=new Main();
        l.root=l.insert(l.root,10);
        l.display(l.root);
    }
}
