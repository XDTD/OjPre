//https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
class Solution {
public:
    void dfs(string s, int pos){
        if(s.size() - pos + us.size() <= ans) 
            return;
        if(pos == s.size()){
            ans = max(ans, (int)us.size());
            return;
        }
        string temp = "";
…        dfs(s, 0);
        return ans;
    }

private:
    int ans = 0;
    unordered_set<string> us;
};