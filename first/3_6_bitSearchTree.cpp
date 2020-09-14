//二叉搜索树
//https://www.nowcoder.com/practice/3d6dd9a58d5246f29f71683346bb8f1b?tpId=63&tqId=29571&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

typedef struct Bitnode{
    int val;
    struct Bitnode* l;
    struct Bitnode* r;
    Bitnode(int c):val(c),l(NULL),r(NULL){};
}Bitnode;

string pre; 
string in;


Bitnode* insertTree(Bitnode *T,int x){
    if(T==NULL){
        T=new Bitnode(x);
        return T;
    }else if(x<T->val){
        T->l=insertTree(T->l,x);  //必须有个赋值
    }else if(x>T->val){
        T->r=insertTree(T->r,x);
    }
    return T;
}

void preOrder(Bitnode* T){
    if(T!=NULL){
        pre+=T->val+'0';
        preOrder(T->l);
        preOrder(T->r);
    }
}

void inOrder(Bitnode* T){
    if(T!=NULL){
        inOrder(T->l);
        in+=T->val+'0';
        inOrder(T->r);
    }
}

int main(){
    int n; //n代表要比较的次数
    while(scanf("%d",&n)!=EOF&&n!=0){
        string pre1;
        string in1;
        for(int i=0;i<n+1;i++){   //n+1不是n
            string tmp;
            cin>>tmp;
            Bitnode* T=NULL;   //初始化！！
            for(int j=0;j<tmp.size();j++){
                T=insertTree(T,tmp[j]-'0');
            }
            pre="";
            in="";
            preOrder(T);
            inOrder(T);
            if(i==0){   //比较母版
                pre1=pre;
                in1=in;
            }else{     //与母版比较
                if(pre==pre1){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}
