//huffman树，小顶堆，注意逻辑
//https://www.nowcoder.com/practice/162753046d5f47c7aac01a5b2fcda155?tpId=67&tqId=29635&tPage=1&ru=/kaoyan/retest/1005&qru=/ta/bupt-kaoyan/question-ranking
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> Q;
    int n;
    while(scanf("%d", &n) != EOF){
        while(n--){
            int temp;
            scanf("%d", &temp);
            Q.push(temp);
        }
        int ans = 0;
        while(Q.size() > 1){
            int a = Q.top(); Q.pop();
            int b = Q.top(); Q.pop();
            int temp = a + b;
            ans += temp;
            Q.push(temp);
        }
        Q.pop();
        printf("%d\n",ans);
    }
    return 0;
}