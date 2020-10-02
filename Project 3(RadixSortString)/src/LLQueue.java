import java.io.*;
import java.util.Scanner;

public class LLQueue {
	private listNode head;
	private listNode tail;
	
	public LLQueue() {
		head = tail = new listNode();
	}
	
	public void insertQ(listNode newNode) {

		if(isEmpty()) {
			head.next = newNode;
			tail = head.next;
		}
		else {
			tail.next= newNode;
			tail = tail.next;
		}

	}
	
	public listNode deleteHead() {
		
		if(isEmpty()) {
			return head;
			
		}
		else {
			listNode oldhead = this.head.next;
			this.head.next = this.head.next.next;
			return oldhead;
			
		} 
	}
	
	
	public boolean isEmpty() {
		return (this.head.next == null);
	}
	
	public listNode buildQueue (Scanner inFile) {
		while(inFile.hasNextInt()) {
			String data = inFile.next();
			listNode newNode = new listNode(data,null);
			insertQ(newNode);
		}
		return head;
		 
	}
	
	public void printQueue(int whichTable,int index,BufferedWriter outFile2) throws IOException {
		LLQueue newHead=new LLQueue();
		listNode node=new listNode();
			if(!isEmpty()) {
				
			outFile2.write("Table["+whichTable+"]["+index+"]:(dummyNode,");
		     while(!isEmpty()) {
		       node = deleteHead();
		       newHead.insertQ(node);
			   if(node.next!=null) {
			   outFile2.write(node.data+")->("+node.data+",");
			   }
		     }
		     outFile2.write(node.data+")->("+ node.data+",NULL) --> NULL");
		     outFile2.newLine();
			}
			this.head=newHead.head;
	
	}

	public void printQueue(BufferedWriter outFile1) throws IOException {
		if(!isEmpty()) {
		while(!isEmpty()) {
			listNode node = deleteHead();
			outFile1.write(node.data);
			outFile1.newLine();	
		}
		}
	}
}

	


