//一个类  表达结点
class Node{
	int value; //保存结点中的数据
    Node next; // 指向下一个结点的引用
	           //null
	public Node(int value){
		this.value=value;
		this.next=null;
	}		   
}
public class Linklist2{
	
	public static Node createLinklist(){
		Node n1=new Node(1);// 首结点（头结点）
		Node n2=new Node(2);
		Node n3=new Node(3);
		Node n4=new Node(4);
        Node n5=new Node(5);  	
	//将所有结点串起来
	    n1.next=n2;
		n2.next=n3;
		n3.next=n4;
		n4.next=n5;
		n5.next=null;
		return n1;
	}
	public static Node pushFront(Node head,int value){
		//1.申请新结点
		Node newNode=new Node(value);
		//2.更新newNode的next  -->head
		newNode.next=head;
		//3.更新head
	    //(head=newNode;)
		
		return newNode;
	}
	public static Node getLast(Node head){
		Node cur=head;
		while(cur.next!=null){
			cur=cur.next;
		}
		return cur;
	}
	public static Node pushBack(Node head,int value){
		if(head==null){
			//对空表尾插
			return pushFront(head,value);
		}else{
			//非空表
		    Node newNode=new Node(value);
		    Node last=getLast(head);
		    last.next=newNode;
		    return head; 	
		}
		 
	}

    public static Node popFront(Node head){
		if (head==null){
			System.out.println("参数不合法！");
			return null;
		}
		return head.next;
	}
	
	public static Node popBack(Node head){
		if (head==null){
			System.out.println("参数不合法！");
			return null;
		}
		if(head.next==null){
			//只有一个结点 头删解决
			return null;
		}else{
			//1.找到倒数第二个结点
			Node llast=getLLast(head);
			//2.让倒数第二个的next=null
			llast.next=null;
			//3.释放最后一个 GC
		}
		return head;
	}
	private static Node getLLast(Node head){
		Node node=head;
		while(node.next.next!=null){
			node=node.next;
		}
		return node;
	}
	
	public static void displayLinklist(Node head){
		//如何遍历一个链表
		for (Node cur=head;cur!=null;cur=cur.next){
			System.out.printf("(%d)-->",cur.value);
		}
		System.out.println("null");
	}
	public static void main(String[] args){
		Node head=createLinklist();
		displayLinklist(head);
		head=pushFront(head,100);
		displayLinklist(head);
		pushBack(head,666);
		displayLinklist(head);
		
		head=null;
		displayLinklist(head);
		head=pushBack(head,1);
		head=pushBack(head,2);
		head=pushBack(head,3);
		head=pushBack(head,4);
		head=pushBack(head,5);
		displayLinklist(head);
		
		head=popFront(head);
		head=popFront(head);
		head=popFront(head);
		displayLinklist(head);
		head=popBack(head);
		displayLinklist(head);
		head=popBack(head);
		displayLinklist(head);
	}
}
 