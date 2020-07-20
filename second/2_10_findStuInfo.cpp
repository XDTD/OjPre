//不用二分，但可以一试
//https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4?tpId=60&tqId=29499&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1001;

struct stu{
    char name[20];
    char sex[10];
    char idx[20];
    int age;
};


int main(){
    int n,m;
    stu stus[N];
    while(scanf("%d",&n) !=EOF  && n!=0){
        for(int i = 0; i < n; i++){
            scanf("%s %s %s %d",stus[i].idx,stus[i].name,stus[i].sex,&stus[i].age);
        }
        scanf("%d",&m);
        while(m--){
            char tmp[20];
            scanf("%s",tmp);
            int target =-1;
            for(int i = 0;i < n; i++){
                if(strcmp(stus[i].idx,tmp) == 0){
                    target = i;
                    break;
                }
            }
            if(target == -1)
                printf("No Answer!\n");
            else{
                stu a = stus[target];
                printf("%s %s %s %d\n",a.idx,a.name,a.sex,a.age);
            }
                
        }
        
    }
    return 0;
}