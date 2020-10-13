//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=60&tqId=29474&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
//成绩排序，要加id表示先后顺序

#include<cstdio>
#include<algorithm>

using namespace std;


struct student{
    char name[20];
    int grade;
    int id;
};

student students[50];

bool ascending(student a, student b){
    return a.grade == b.grade? a.id < b.id : a.grade < b.grade;
}

bool descending(student a, student b){
    return a.grade == b.grade ? a.id < b.id : a.grade > b.grade;
}


int main(){
    int n, flagOfSort;
    while (scanf("%d", &n) != EOF){
        scanf("%d", &flagOfSort);
        for(int i = 0; i < n; i++){
            scanf("%s %d", students[i].name, &students[i].grade);
            students[i].id = i;
        }
        if(flagOfSort == 1)
            sort(students, students+n, ascending);
        else
            sort(students, students+n, descending);
        for(int i = 0; i < n; i++){
            printf("%s %d\n", students[i].name, students[i].grade);
        }
    }
    return 0;
    
}