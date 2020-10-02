//
//  main.cpp
//  HuffmanCoding
//
//  Created by Lin on 9/22/20.
//  Copyright  2020 Lin. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class treeNode{
public:
    string chStr;
    int frequency;
    string code;
    treeNode* left;
    treeNode* right;
    treeNode* next;
    
    treeNode(string chStr1,int frequency1,string code1,treeNode* left1,treeNode* right1,treeNode* next1){
         chStr=chStr1;
         frequency=frequency1;
         code=code1;
         left=left1;
         right=right1;
         next=next1;
    }
    
     treeNode(){
         chStr="dummynode";
         frequency=0;
         code="";
         left=NULL;
         right=NULL;
         next=NULL;
     }
    
     void printNode(treeNode* T,ofstream& DeBugfile){
         
         DeBugfile<<"("<<T->chStr<<", "<<T->frequency<<","<<T->code<<",";
         if(T->next!=NULL){
             DeBugfile<<T->next->chStr;
         }else{
             DeBugfile<<"NULL";}
         
         if(T->left!=NULL && T->right!=NULL){
             DeBugfile<<","<<T->left->chStr<<","<<T->right->chStr<<")->";
         }else{
             DeBugfile<<",NULL,NULL)->";
         }
         
     }
     
      void printNode1(treeNode* T,ofstream& DeBugfile){
         
         DeBugfile<<"("<<T->chStr<<", "<<T->frequency<<","<<T->code<<",";
         if(T->next!=NULL){
             DeBugfile<<T->next->chStr;
         }else{
             DeBugfile<<"NULL";}
         
         if(T->left!=NULL && T->right!=NULL){
             DeBugfile<<","<<T->left->chStr<<","<<T->right->chStr<<")"<<endl;
         }else{
             DeBugfile<<",NULL,NULL)"<<endl;
         }
         
     }
};

class linkedList:public treeNode{
public:
    treeNode* listHead;

    linkedList(){
        listHead=new treeNode();

    }
    treeNode* findSpot(treeNode* listHead,treeNode* newNode)
    {
        treeNode* spot = listHead;
        while(spot->next != NULL && newNode->frequency > spot->next->frequency) {
            spot=spot->next;
        }
        return spot;
    }
    void InsertOneNode(treeNode* listHead,treeNode* newNode){
        
        treeNode* spot=findSpot(listHead,newNode);
        newNode->next=spot->next;
        spot->next=newNode;
    }


    void printList(treeNode* listHead,ofstream &getfile){

        treeNode* p=new treeNode();

        p=listHead;
        while(p->next->next!=NULL)
        {
            p->printNode(p,getfile);
            p=p->next;
        }
        getfile<<"("<<p->chStr<<","<<p->frequency<<","<<p->code<<",NULL,NULL,NULL)"<<endl;
        
    }
};

class BinaryTree:public treeNode{
public:
    treeNode* Root;
    
    BinaryTree(){
        Root = new treeNode();
    }
    
    void preOrderTraversal (treeNode* Root,ofstream& DebugFile){
        if(isLeaf(Root)){
            Root->printNode1(Root, DebugFile);
         }else{
             Root->printNode1(Root, DebugFile);
             preOrderTraversal(Root->left,DebugFile);
             preOrderTraversal(Root->right,DebugFile);
        
         }
    }
    
    void  inOrderTraversal (treeNode* Root,ofstream& DebugFile){
        if(isLeaf(Root)){
            Root->printNode1(Root, DebugFile);
         }else{
             inOrderTraversal(Root->left,DebugFile);
             Root->printNode1(Root, DebugFile);
             inOrderTraversal(Root->right,DebugFile);
           
         }
        
    }
    
    void postOrderTraversal(treeNode* Root,ofstream& DebugFile){
        if(isLeaf(Root)){
            Root->printNode1(Root, DebugFile);
             }
             else{
                 postOrderTraversal(Root->left,DebugFile);
                 postOrderTraversal(Root->right,DebugFile);
                 Root->printNode1(Root, DebugFile);
             }
        
    }
    
    bool isLeaf (treeNode* node){
        if(node->left == NULL && node->right == NULL){
            return true;
        }
        return false;
    }
    
};
class HuffmanCoding:public BinaryTree,public linkedList{
public:
    int charCountAry[256];
    string charCode[256];
    
    void computeCharCounts(ifstream& inFile){
        char ch;
        while(inFile.get(ch)){
            int index = (int)ch;
            charCountAry[index]++;
        }
    }
    
    void printCountAry(ofstream& DebugFile){
        int index=0;
        while(index<256){
            if(charCountAry[index]>0){
                if(index<32){
                    DebugFile<<"\\n "<<charCountAry[index]<<endl;
                }else{
                    DebugFile<<(char)index<<" "<<charCountAry[index]<<endl;
                }
            }
            index++;
        }
    }
    
    void constructHuffmanLList(linkedList* lh,int charCountAry[],ofstream& DebugFile){
        int index = 0;
        int prob;
        string chr;
        
        while(index<256){
            if(charCountAry[index]>0){
			chr=char(index);
            prob=charCountAry[index];
        	treeNode *newNode=new treeNode(chr,prob,"",NULL,NULL,NULL);
            lh->InsertOneNode(lh->listHead,newNode);
            lh->printList(lh->listHead,DebugFile);
            }
            index++;
        }
    }
    
    void constructHuffmanBinTree(linkedList* lh,ofstream& outFile,BinaryTree* bt){
        
        while(lh->listHead->next->next !=NULL){
            
            treeNode* newNode =new treeNode();
            newNode->frequency=(lh->listHead->next->frequency)+(lh->listHead->next->next->frequency);
            newNode->chStr=(lh->listHead->next->chStr)+(lh->listHead->next->next->chStr);
            newNode->left = lh->listHead->next;
            newNode->right=lh->listHead->next->next;
            newNode->next=NULL;
            lh->InsertOneNode(lh->listHead,newNode);
            lh->listHead->next=lh->listHead->next->next->next;
            lh->printList(lh->listHead,outFile);
        }
        bt->Root = lh->listHead->next;
        
    }
    
    void constructCharCode (treeNode* T,string code){
        if(isLeaf(T)){
            T->code=code;
           
            int Index = (int)(T->chStr.at(0));
            charCode[Index]=code;
        }else{
            constructCharCode(T->left,code+"0");
            
            constructCharCode(T->right,code+"1");

        }

    }
    
    void Encode(ifstream& orgFile,ofstream& compFile){
        char charIn;
        while(orgFile.get(charIn)){
            int index = (int)charIn;
            string code= charCode[index];
            compFile<<code;
        }
    }
    
    void Decode(treeNode* Root,ifstream& inFile,ofstream& outFile){
        treeNode* Spot = Root;
        char oneBit;
        
        while(inFile.get(oneBit)){
        if(isLeaf(Spot)){
            outFile<<Spot->chStr;
            Spot=Root;
        }
            if(oneBit=='0'){
            Spot=Spot->left;
            }else if (oneBit=='1'){
            Spot=Spot->right;
            }else{
            cout<<"Error! The compress file contains invalid character!"<<endl;
            exit(0);
            }
        }
        if(inFile.eof() && !isLeaf(Spot)){
            cout<<"Error: The compress file is corrupted!"<<endl;
        }
    }
    
    void userInterface(treeNode* T){
        string nameOrg;
        string nameCompress;
        string nameDeCompress;
        char yesNo;
        
        do{
            cout<<"Do you want to encode a file?(Y/N)"<<endl;
            cin>>yesNo;
        
            if(yesNo=='N'){
                exit(0);
            }else{
                cout<<"Please enter the file name: "<<endl;
                cin>>nameOrg;
            }
            
            nameCompress=nameOrg.substr(0,nameOrg.find_last_of('.'))+"_Compressed.txt";
            nameDeCompress=nameOrg.substr(0,nameOrg.find_last_of('.'))+"_DeCompress.txt";
        
            ifstream orgFile(nameOrg);
            ofstream compFile(nameCompress);
            ofstream deCompFile(nameDeCompress);
        
            Encode(orgFile,compFile);
            compFile.close();
            
            
            ifstream compFile1(nameCompress);
            
            Decode(T,compFile1,deCompFile);
            
            orgFile.close();
            compFile1.close();
            deCompFile.close();
        }while(yesNo=='Y');
    }
    
};

int main(int argc, const char * argv[]) {
    
    string nameInFile=argv[1];
    ifstream inFile(nameInFile);
    string nameDebugFile=nameInFile.substr(0,nameInFile.find_last_of('.'))+"_DeBug.txt";
    ofstream DebugFile(nameDebugFile);
    
    HuffmanCoding* hc= new HuffmanCoding();
    linkedList* lh = new linkedList();
    BinaryTree* bt = new BinaryTree();
    hc->computeCharCounts(inFile);
    
    hc->printCountAry(DebugFile);
    
    hc->constructHuffmanLList(lh,hc->charCountAry,DebugFile);
    
    hc->constructHuffmanBinTree(lh,DebugFile,bt);
    DebugFile<<endl;
    DebugFile<<endl;
    
    hc->constructCharCode(bt->Root,"");
    
    DebugFile<<"PreOrder Traversal"<<endl;
    bt->preOrderTraversal(bt->Root, DebugFile);
    DebugFile<<endl;

	DebugFile<<endl;
	DebugFile<<endl;
    DebugFile<<"InOrder Traversal"<<endl;
    bt->inOrderTraversal(bt->Root, DebugFile);
    DebugFile<<endl;

	DebugFile<<endl;
	DebugFile<<endl;
    DebugFile<<"PostOrder Traversal"<<endl;
    bt->postOrderTraversal(bt->Root, DebugFile);
    DebugFile<<endl;

    hc->userInterface(bt->Root);
    
    inFile.close();
    DebugFile.close();
    
    
    
}
