
import java.io.*;
import java.util.Scanner;

public class LLStack {
	
	private listNode top;
	
	
	public LLStack() {
		
		top = new listNode();
	
	}
	

	public void push(listNode newNode) {
		
		newNode.next=top;
		top=newNode;
		
	}
	
	public listNode pop() {
		listNode currNode=this.top;
		this.top=this.top.next;
		return currNode;
	}
	
	public boolean isEmpty() {
		
		return (this.top.next == null);
	}
	
	public void printTop(listNode S) {
		
	}
	
	
	public listNode buildStack(Scanner inFile) {
		
		while(inFile.hasNextInt()) {
			int data = inFile.nextInt();
			listNode newNode = new listNode(data,null);
			push(newNode);
		}
		return top;
	}

	public void dumpStack(BufferedWriter outFile1) throws IOException {
		
		while(!isEmpty()) {
			listNode node = pop();
			outFile1.write(Integer.toString(node.data));
			outFile1.newLine();	
		}
	}
		
	
	}


