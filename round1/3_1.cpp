//有效的括号，栈的应用
//https://leetcode-cn.com/problems/valid-parentheses/

#include<stack>
#include<iostream>
using namespace std;

bool isValid(string s) {
    stack<char> sk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            sk.push(s[i]);
        }else{
            if(s[i]==')'&&!sk.empty()&&sk.top()=='(') sk.pop();
            else if(s[i]==']'&&!sk.empty()&&sk.top()=='[') sk.pop();
            else if(s[i]=='}'&&!sk.empty()&&sk.top()=='{') sk.pop();
            else return false;
        }
    }
    if(sk.empty())
        return true;
    return false;
}

int main(){
    string s="()[]{}";
    cout<<isValid(s)<<endl;
    return 0;
}