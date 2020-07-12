//哈夫曼树,小顶堆
//https://www.nowcoder.com/practice/162753046d5f47c7aac01a5b2fcda155?tpId=67&tqId=29635&tPage=1&ru=/kaoyan/retest/1005&qru=/ta/bupt-kaoyan/question-ranking
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

int main(){
    int n;
    priority_queue<int,vector<int>,greater<int>> Q;
    while(scanf("%d",&n)!=EOF){
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            Q.push(tmp);
        }
        int ans=0;
        while(Q.size()>1){
            int a=Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            ans+=a+b;
            Q.push(a+b);
        }
        printf("%d",ans);
    }
    return 0;
}