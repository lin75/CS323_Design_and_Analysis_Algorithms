import java.io.*;
import java.util.*;

public class main {

	public static void main(String[] args) throws IOException {
		String str = args[0];
		
		Scanner inFile1=new Scanner(new FileReader(str));
		BufferedWriter outFile1 = new BufferedWriter(new FileWriter(new File(args[1])));
		
		LLStack stack = new LLStack();
		listNode S= stack.buildStack(inFile1);
		stack.dumpStack(outFile1);
		
		inFile1.close();
		outFile1.close();
		
		Scanner inFile2=new Scanner(new FileReader(str));
		BufferedWriter outFile2 = new BufferedWriter(new FileWriter(new File(args[2])));
		
		LLQueue queue = new LLQueue();
		listNode Q= queue.buildQueue(inFile2);
		queue.dumpQueue(outFile2);
		
		inFile2.close();
		outFile2.close();
		
		
		Scanner inFile3=new Scanner(new FileReader(str));
		BufferedWriter outFile3 = new BufferedWriter(new FileWriter(new File(args[3])));
		
		LList orderlist = new LList();
		listNode O = orderlist.buildList(inFile3);
		orderlist.printList(outFile3);
		
		inFile3.close();
		outFile3.close();
	}

}
