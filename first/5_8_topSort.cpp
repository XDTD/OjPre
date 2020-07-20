#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
//因为一件事做完了，那么就直接可以做下一件事了，a-->b，可是如果有两次输入的话，本来已经结束的关系
//还会有一条边
//今天又发现一个问题，就是优先队列不要最后才扔，因为中间添加一个数之后，不知道该扔的这个还在不在前面
//所以记住k的这种表达方式
int Map[501][501];
int in_degree[501];

int main()
{
   int n,m;
   while(~scanf("%d%d",&n,&m))
   {
       priority_queue<int,vector<int>,greater<int> > pq;
       memset(Map,0,sizeof(Map));
       memset(in_degree,0,sizeof(in_degree));

       for(int i=1;i<=m;i++)
       {
           int a,b;
           scanf("%d%d",&a,&b);
           if(Map[a][b]==0)//保证相同的关系，只有一条边,要不然的话，会出现本来入度是0，还是1
               in_degree[b]++;
           Map[a][b]=1;
       }

       for(int i=1;i<=n;i++)
       {
           if(in_degree[i]==0)
           {
                pq.push(i);
           }
       }
       int k=1;//
       while(pq.size())//反正下次输出的是入度为0的点，优先队列自动保持，根本不用管的
       {
           int temp=pq.top();//长教训了，下次不管怎么样都会先扔掉，不知道下面扔的话，还是不是这个数小
             pq.pop();

           for(int i=1;i<=n;i++)
           {
               if(Map[temp][i])//先根据这个起点，找到所有和他相邻的边，改变他们的入度
               {
                   in_degree[i]--;//同时相邻的点的入度-1
                   if(in_degree[i]==0)//如果入度为0，就把他放入队列，因为我们要输出了
                     pq.push(i);
               }
               Map[temp][i]=0;//以队首为起点的边会全部消失
           }

           if(k==1)
             printf("%d",temp);//
           else
             printf(" %d",temp);//

           k=0;//
       }
       printf("\n");
   }
   return 0;
}