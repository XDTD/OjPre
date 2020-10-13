#include<string>
#include<cstdio>
#include<iostream>
using namespace std;



void seek(string A,string B){
    if(A.size()>0){
        char ch=B[B.size()-1];
        int idx=A.find(ch);
        cout<<ch;
        seek(A.substr(0,idx),B.substr(0,idx));
        seek(A.substr(idx+1),B.substr(idx,A.size()-idx-1));
    }
}

int main(){
    string A,B;
    cin>>A>>B;
    seek(A,B);
    return 0;
}