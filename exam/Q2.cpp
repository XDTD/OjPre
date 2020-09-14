#include<vector>

using namespace std;

    /**
     * 
     * @param n int整型 
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int check(int x,vector<int> a){
        for(int i = 0; i < a.size(); i++){
            if(x == a[i])
                return 1;
        }
        return 0;
    }

    int work(int n, int* a, int aLen) {
       vector<int> b = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
       int ans = n;
       for(int i = 0;i < n -1; i++){
           if(check(a[i+1] - a[i], b)) continue;
           else ans++;
       }
       return ans;
    }

    int main(){
        return 0;
    }