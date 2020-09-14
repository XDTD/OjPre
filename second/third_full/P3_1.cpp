//括号匹配
//https://leetcode-cn.com/problems/valid-parentheses/
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s){
    stack<char> sk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            sk.push(s[i]);
        }
        else if(s[i] == ')' && !sk.empty() && sk.top() == '(') sk.pop();
        else if(s[i] == ']' && !sk.empty() && sk.top() == '[') sk.pop();
        else if(s[i] == '}' && !sk.empty() && sk.top() == '{') sk.pop();
        else return false;
    }
    if(!sk.empty())
        return false;
    return true;
}

int main(){
    string s ="()";
    printf("%d", isValid(s));
    return 0;
}

