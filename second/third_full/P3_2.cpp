//简单计算器，调试了很多次，问题很大
//https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=63&tqId=29576&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
stack<float> nums;
stack<char> op;
char temp[240];
int getPrivoty(char s){
    if(s == '+' || s == '-') return 1;
    if(s == '*' || s =='/') return 2;
    return 0;  //数字返回0
}

void calculate(){
    char s = op.top(); op.pop();
    float a = nums.top(); nums.pop();
    float b = nums.top(); nums.pop();    
    float ans;
    if(s == '+') ans = b + a;
    if(s == '-') ans = b - a;
    if(s == '*') ans = b * a;
    if(s == '/') ans = b / a;
    nums.push(ans);
}

int main(){
    int lenOfTemp;
    while(gets(temp) ){
        if(strcmp(temp, "0") == 0) break;
        lenOfTemp = strlen(temp);
        while(!op.empty())  op.pop();
        while(!nums.empty())  nums.pop();

        for(int i = 0; i < lenOfTemp; i++){
            if(temp[i] == ' ') continue; //为空格
            if(temp[i] >= '0' && temp[i] <= '9'){
                float curNum = 0;
                while(temp[i] >= '0' && temp[i] <= '9'){    
                    curNum = curNum * 10 + (float)temp[i] - '0';
                    i++;
                }
                nums.push(curNum);
            }else if(op.empty() || getPrivoty(temp[i]) > getPrivoty(op.top())){
                op.push(temp[i]);
            }else{
                while(!op.empty() && getPrivoty(temp[i]) <= getPrivoty(op.top())) 
                    calculate();
                op.push(temp[i]);
            }
        }
        while(!op.empty()){
            calculate();
        }
        printf("%.2f\n", nums.top());
    }
    return 0;
}