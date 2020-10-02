import java.io.*;
import java.util.Scanner;

public class LList {

	listNode listHead;
	
	public LList() {
		listHead = new listNode();
		
	}
	
	
	public listNode findSpot(listNode newNode) {
		listNode spot = listHead;
		while(spot.next != null && newNode.data > spot.next.data) {
			spot=spot.next;
		}
		
		return spot;
	}
	
	public void inserOneNode(listNode spot, listNode newNode) {
		newNode.next = spot.next;
		spot.next = newNode;
	}
	
	public listNode buildList(Scanner inFile) {
		
		int data=0;
		
		while(inFile.hasNextInt()) {
			data=inFile.nextInt();
			listNode node = new listNode(data,null);
			listNode spot=findSpot(node);
			inserOneNode(spot,node);
		}

		return listHead;
	}
	
	public void printList(BufferedWriter outFile3) throws IOException {
		
		listNode node = this.listHead;
		
		outFile3.write("listHead -->");
		
		while(node.next != null) {
			outFile3.write("("+Integer.toString(node.data)+","
								+Integer.toString(node.next.data)+")"+" -->");
			node = node.next;
			
		}
		outFile3.write("("+Integer.toString(node.data)+",NULL) --> NULL");
		
			
		
	
	}
	
	
		
	}