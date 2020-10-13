//简单计算器，栈的应用
//https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=63&tqId=29576&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

stack<double> nums;
stack<char>  op;
char str[210];
//获取运算符优先级
int getPriority(char s){
    if(s=='#') return 1;
    else if(s=='+'||s=='-') return 2;
    else if(s=='*'||s=='/') return 3;
    else return 0;
}

void calculate(){
    char s=op.top();op.pop();
    double b=nums.top();nums.pop();
    double a=nums.top();nums.pop();
    double ans;
    if(s=='+') ans=a+b;
    else if(s=='-') ans=a-b;
    else if(s=='*') ans=a*b;
    else if(s=='/') ans=a/b;
    nums.push(ans); 
}

int main(){
    int len;
    while(gets(str)){
        if(strcmp(str,"0")==0) break;
        while(!op.empty()) op.pop();
        while(!nums.empty()) nums.pop();
        len=strlen(str);
        op.push('#');
        for(int i=0;i<len;i++){
            if(str[i]!=' '){
                double x=0,t;
                if(isdigit(str[i])){
                    while(isdigit(str[i])){
                        t=(double)(str[i++]-'0');
                        x=x*10+t;
                    }
                    nums.push(x);
                }else{
                    while(getPriority(str[i])<=getPriority(op.top())){
                        calculate();
                    }
                    op.push(str[i]);
                }
            }
        }
        while(op.top()!='#'){
            calculate();
        }
        printf("%.2lf\n",nums.top());
    }
    return 0;
}