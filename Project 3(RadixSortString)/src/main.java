import java.io.*;
import java.util.*;

public class main {

	public static void main(String[] args)throws IOException {
		
		Scanner inFile=new Scanner(new FileReader(args[0]));
		BufferedWriter outFile1 = new BufferedWriter(new FileWriter(new File(args[1])));
		BufferedWriter outFile2 = new BufferedWriter(new FileWriter(new File(args[2])));
		
		RSort R = new RSort();
		R.firstReading(inFile);
		inFile.close();

		Scanner inFile1=new Scanner(new FileReader(args[0]));
		LLStack S = new LLStack();
		S.loadStack(R,inFile1);
		S.printStack(S,outFile2);

		
		R.currentPosition = R.longestStringLength-1;
		R.currentTable=0;
		R.moveStack(R.hashTable,S,R.currentPosition,R.currentTable);
		R.printTable(R.hashTable[R.currentTable],R.currentTable,outFile2);
		
		while(R.currentPosition>0) {
		R.currentPosition--;
		R.nextTable =(R.currentTable+1)%2;
		int currentQueue = 0;
		 
		while(currentQueue<256) {
		while(!R.hashTable[R.currentTable][currentQueue].isEmpty()) {
			listNode node = R.hashTable[R.currentTable][currentQueue].deleteHead();
			listNode newnode = new listNode(node.data,null);
			char chr=R.getChar(newnode, R.currentPosition);
			int hashIndex=(int)chr;
			R.addTail(R.hashTable[R.nextTable][hashIndex],newnode);
		}
		
			currentQueue++;
		}
		
		R.printTable(R.hashTable[R.nextTable],R.nextTable,outFile2);
			

		
		R.currentTable=R.nextTable;
		}
		
		R.PrintSortedData(R.hashTable[R.nextTable],outFile1);
		
		
		
		outFile1.close();
		outFile2.close();
		inFile1.close();
		
	}

}
