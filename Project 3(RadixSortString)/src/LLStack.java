import java.io.*;
import java.util.Scanner;

public class LLStack {
	
	listNode top;
	
	
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
	
	public void loadStack(RSort R,Scanner inFile) {

		while(inFile.hasNext()) {
			String data = inFile.next();
			String paddedData = R.padString(data);
			listNode newNode = new listNode();
			newNode.data = paddedData;
			push(newNode);
		}
	} 

	public void printStack(LLStack S,BufferedWriter outFile2) throws IOException {
		
		listNode head=top;
		while(!isEmpty()) {
			listNode node = pop();
			outFile2.write(node.data);
			outFile2.newLine();	
		}
		outFile2.newLine();
		top=head;
	}
		
}
