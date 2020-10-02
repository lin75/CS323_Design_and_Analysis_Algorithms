import java.io.*;
import java.util.*;

public class RSort {

	LLQueue[][] hashTable;
	String data;
	int currentTable;
	int nextTable;
	int longestStringLength;
	int currentPosition;
	
	public RSort(){
		hashTable=new LLQueue[2][256];
		for(int i=0;i<2;i++) {
			for(int j=0;j<256;j++) {
				hashTable[i][j]=new LLQueue();
			}
		}
		
	};
	public void firstReading(Scanner inFile) {
		
		longestStringLength=0;
		while(inFile.hasNext()) {
			String data = inFile.next();
			if(data.length() >longestStringLength)
				longestStringLength=data.length();//7
		}
	}
	
	public LLStack loadStack(Scanner inFile) {
		LLStack S = new LLStack();
		S.top = null;
		while(inFile.hasNext()) {
			String data = inFile.next();
			String paddedData = padString(data);
			listNode newNode = new listNode();
			newNode.data = paddedData;
			S.push(newNode);
		}
		return S;
	}
	
	public void moveStack(LLQueue[][] hashTable, LLStack S,int currentPosition,int currentTable) {
		
		while(!S.isEmpty()) {
		listNode node = S.pop();
		listNode newnode = new listNode(node.data,null);
		char chr = getChar(newnode,currentPosition);
		
		int hashIndex=(int)chr;     
		
		addTail(hashTable[currentTable][hashIndex],newnode);// move node out of stack 
		
		}                                                // and then put node into queue
	}
	
	public void addTail(LLQueue llQueue, listNode node) {
		
		
		llQueue.insertQ(node);	
}

	public void tableIndex() {
		
	}
	
	public char getChar(listNode node,int currentPosition) {
		return node.data.charAt(currentPosition);
		
	}
	
	public String padString(String data) {
		while(data.length()<longestStringLength) {
			data=data+" ";
		}
		return data;
		
	}
	

	public void printTable(LLQueue[] hashTable, int nextTable, BufferedWriter outFile2) throws IOException {
		
		for(int i=0;i<hashTable.length;i++) 
			hashTable[i].printQueue(nextTable, i, outFile2);
		
		
	}
	

	public void PrintSortedData(LLQueue[] hashTable,BufferedWriter outFile1) throws IOException{
		
		for(int i=0;i<hashTable.length;i++) 	
			hashTable[i].printQueue(outFile1);
		

	}

	
	

}
