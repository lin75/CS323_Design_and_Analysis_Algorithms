import java.util.*;

public class listNode {
	int data;
	listNode next;
	
	public listNode(){
		data = -99999;//dummy node
		next= null;
	};
	
	
	public listNode(int data,listNode next) {
		this.data=data;
		this.next=next;
	}
	
}
