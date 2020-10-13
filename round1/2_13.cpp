# include<stdio.h>
typedef struct{
    int id;
    char name[100];
    char sex[20];
    int grade;
}Student;
int main(){
    Student stu[10000];
    int n,m,i,j,k,flag,no;
    while(scanf("%d",&n)!=EOF){
         
       for(i=0;i<n;i++){
           scanf("%d%s%s%d",&stu[i].id,stu[i].name,stu[i].sex,&stu[i].grade);
       }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            flag=0;
            scanf("%d",&no);
            for(j=0;j<n;j++){
                if(no==stu[j].id){
                   printf("%d %s %s %d\n",stu[j].id,stu[j].name,stu[j].sex,stu[j].grade);
                    flag=1;
                    break;
                }
                     
            }
            if(flag==0)
                 printf("No Answer!\n");
        }
 
    }
    return 0;
}