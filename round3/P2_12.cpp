//今年暑假不AC，贪心算法
//http://acm.hdu.edu.cn/showproblem.php?pid=2037
#include<cstdio>
#include<algorithm>

using namespace std;

struct program{
    int beginTime;
    int endTime;
};

const int N = 101;
program programList[N];

bool cmp(program a, program b){
    return a.endTime < b.endTime;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &programList[i].beginTime, &programList[i].endTime);
        }
        sort(programList, programList + n, cmp);
        int curTime = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(programList[i].beginTime >= curTime){  //等于号
                ans ++;
                curTime = programList[i].endTime;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}