//成绩排序，重载
//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=60&tqId=29474&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<algorithm>

using namespace std;

struct student{
    int score;
    char name[20];
    int idx;
};


const int N = 1001;
student stus[N];

//升序
bool cmp_up(student a, student b){
    return a.score==b.score?a.idx < b.idx:a.score < b.score;
}

//降序
bool cmp_down(student a, student b){
    return a.score==b.score?a.idx < b.idx:a.score > b.score;
}

int main(){
    int n,flag;
    while(scanf("%d",&n) != EOF){
        scanf("%d",&flag);
        for(int i = 0; i < n; i++){
            scanf("%s",stus[i].name);
            scanf("%d",&stus[i].score);
            stus[i].idx = i;
        }
        if(flag == 0)
            sort(stus,stus+n,cmp_down);
        else 
            sort(stus,stus+n,cmp_up);
        for(int i = 0; i < n; i++){
            printf("%s %d\n",stus[i].name,stus[i].score);
        }
    }
    return 0;
}