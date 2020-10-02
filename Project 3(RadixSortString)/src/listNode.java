import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

public class listNode {
	String data;
	listNode next;
	
	public listNode(){
		data= "dummyNode";
		next= null;
	};
	
	 
	public listNode(String data,listNode next) {
		this.data=data;
		this.next=next;
	}
	
	public void printNode(listNode node,BufferedWriter outFile1) throws IOException {
		outFile1.write("("+node.data +","+node.next.data+")->");
	}
	
}

