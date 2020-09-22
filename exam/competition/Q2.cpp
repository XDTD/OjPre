#include<string>
#include<iostream>
#include<algorithm>
#include <map>

using namespace std;

int subFun(string s){
    map<string, int> mp;
    int ans = 0;
    for(int i = 0; i < s.size();i++){
        string tmp = "";
        tmp.push_back(s[i]);
        while(mp.find(tmp) != mp.end() && i < s.size() - 1){
            i++;
            tmp.push_back(s[i]);
        }
        if(mp.find(tmp) == mp.end()){
            ans++;
             mp[tmp] = 1;
        }

    }
    return ans;
}

int maxUniqueSplit(string s) {
    int ans = maxUniqueSplit(s);
    reverse(s.begin(), s.end());
    return max(ans, maxUniqueSplit(s));
}

int main(){
    string s = "aa";
    cout << maxUniqueSplit(s) << endl;
    return 0;
}