//特殊乘法，没啥好注意的
//https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f?tpId=60&tqId=29490&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<iostream>

using namespace std;

int main(){
    string num1, num2;
    while(cin >> num1 >> num2){
        int ans = 0;
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                ans += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}