//https://leetcode-cn.com/problems/rearrange-spaces-between-words/
#include<string>
#include<iostream>
using namespace std;


string reorderSpaces(string text) {
    int countOfAll = 0, count = 0; 
    int splitNum = 0, lastNum = 0;
    for(int i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            int temp = i;
            while(text[i] == ' '){
                countOfAll++;
                i++;
            }
            if(i < text.size() && temp != 0)
                count++;
        }
    }
    splitNum = count == 0? 0 : countOfAll / count;
    lastNum = count == 0? countOfAll: countOfAll % count;
    string newStr = "";
    for(int i = 0; i < text.size();){
        if(text[i] == ' '){
            int temp = i;
            while(text[i] == ' '){
                i++;
            }
            if(temp != 0 && i < text.size()){
                for(int j = 0; j < splitNum; j++){
                    newStr += " ";
                }
            }
        }else{
            newStr += text[i];
            i++;
        }
    }
    for(int j = 0; j < lastNum; j++){
        newStr += " ";
    }
    return newStr;
}


int main(){
    string s1 = "  walks  udp package   into  bar a";
    cout << reorderSpaces(s1) << "flag"<<endl;
    return 0;
}
