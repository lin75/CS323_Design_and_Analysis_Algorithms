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
	
	public listNode deleteQ() {
		
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
			int data = inFile.nextInt();
			listNode newNode = new listNode(data,null);
			insertQ(newNode);
		}
		return head;
		
	}
	
	public void dumpQueue(BufferedWriter outFile2) throws IOException {
		while(!isEmpty()) {
			listNode node = deleteQ();
			outFile2.write(Integer.toString(node.data));
			outFile2.newLine();	
		}
		
	}

}
