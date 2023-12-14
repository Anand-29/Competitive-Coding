public class Main
{
    class Node{
        int data;
        Node next;
        Node(int d){
            data=d;
            next=null;
        }
    }
 Node head=null;
 void insert(int d){
        Node newnode=new Node(d);
        if(head==null){
            head=newnode;
        }
        else{
            Node t=head;
            while(t.next!=null){
                t=t.next;
            }
            t.next=newnode;
        }
            
    }
    void display(){
        Node t=head;
        while(t!=null){
            System.out.print(t.data);
            t=t.next;
        }
    }
	public static void main(String[] args) {
	Main ob=new Main();
	ob.insert(10);
	ob.insert(10);
	ob.insert(10);
	ob.insert(10);
	ob.display();
	}
}
