//
//  main.cpp
//  NewPasswordCheck
//
//  Created by Lin on 9/5/20.
//  Copyright © 2020 Lin. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

string password;
string secondPassword;
int passwordLength;
int charCount[5];

class passWordChecker{
public:

    passWordChecker(){
    }

    void displayRules (ofstream& outfile){
        
        string s1="Create your password\n";
        
        string s2="Password Rule\n1) password is shorter than 8 \n2) password is long than 32\n3) password contains one or two special symbols that are not legal\n4) password does not contain at least one numerical\n5) password does not contain at least one upper case letter\n6) password does not contain at least one lower case letter\n7) password does not contain at least one of legal special characters\n";
        
        cout<<s1;
        cout<<s2;
        outfile<<s1<<s2;
    }

    void askPasswd(ofstream& outfile){
        string s1 ="Please enter your password\n";
        cout<<s1;
        outfile<<s1;
    }

    void displaySucess(ofstream& outfile){
        string s1 ="your password will be updated in a few minutes\n";
        cout<<s1;
        outfile<<s1;
    }

    void displayFail(ofstream& outfile){
        string s1="your password failed one or more password rules\n";
        cout<<s1;
        outfile<<s1;
    }

    void displayMatchFail(ofstream& outfile){
        string s1="Match fail... \n";
        cout<<s1;
        outfile<<s1;
    }

    int checkCharType(char ch){
        
        if(57>=(int)ch and (int)ch>=48){
            return 1;
        }else if(122>=(int)ch and (int)ch>=97){
            return 2;
        }else if(90>=(int)ch and (int)ch>=65){
            return 3;
        }else if((38>=(int)ch and (int)ch>=35)||(42>=(int)ch and (int)ch>=40)||94==(int)ch){
            return 4;
        }
        return 0;
    }

    int checkRules(){
        if(charCount[0]==0 and
           charCount[1]>=1 and
           charCount[2]>=1 and
           charCount[3]>=1 and
           charCount[4]>=1)
            return 1;
        return 0;
    }

    int matching(string s1,string s2){
        if(s1 != s2) return 0;
        return 1;
    }



};

int main(int argc,const char *argv[ ])
{
    ofstream outFile(argv[1]);
    
    passWordChecker pw;
    int validYesNo = 0;
    int matchYesNo = 0;
    
    do{
    do{
    pw.displayRules(outFile);
    bool cond=true;
    do{
        pw.askPasswd(outFile);
        cin>>password;
        outFile<<password<<endl;
        passwordLength = password.length();
        if(passwordLength>=8 and passwordLength<=32){
            cond=false;
        }
    }while(cond);
    
    for(int i=0;i<password.length();i++){
       int index = pw.checkCharType(password[i]);
        charCount[index]++;
    }
    
    validYesNo = pw.checkRules();
        if(validYesNo!=1) pw.displayFail(outFile);
    }while(validYesNo == 0);
    
    string retype = "Please retype the password\n";
    cout<<retype;
    outFile<<retype;
    
    cin>>secondPassword;
    outFile<<secondPassword<<endl;
    
    matchYesNo = pw.matching(password, secondPassword);
    if(matchYesNo ==0) pw.displayMatchFail(outFile);
    }while(matchYesNo == 0);
    
    pw.displaySucess(outFile);
    
    outFile.close();

    return 0;
}
