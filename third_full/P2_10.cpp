//输入N个学生的信息然后查询，注意用字符串不用int储存学生id
//https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4?tpId=40&tqId=21358&qru=/ta/kaoyan/question-ranking

#include<cstdio>
#include<cstring>
const int N = 1001;

struct student{
    int age;
    char id[10];
    char name[20];
    char sex[20];
};

student stus[N];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%s %s %s %d", stus[i].id, stus[i].name, stus[i].sex, &stus[i].age);
        }
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            char temp[10], flag = -1;
            scanf("%s", temp);
            for(int j = 0; j < n; j++){
                if(strcmp( temp, stus[j].id) == 0){
                    printf("%s %s %s %d\n",  stus[j].id, stus[j].name, stus[j].sex, stus[j].age);
                    flag = 1;
                    break;
                }
            }
            if(flag == -1){
                printf("No Answer!\n");
            }
        }
    }
    return 0;
}
