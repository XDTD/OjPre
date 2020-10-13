//二叉排序树
//https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3?tpId=69&tqId=29670&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking

#include<cstdio>
#include<iostream>
const int N=101;
using namespace std;

typedef struct Bitnode{
    int val;
    struct Bitnode* l;
    struct Bitnode* r;
    Bitnode(int c):val(c),l(NULL),r(NULL){};
}Bitnode;


Bitnode* insertTree(Bitnode* T,int x){
    if(T==NULL){
        T=new Bitnode(x);
        return T;
    }else if(x<T->val){
        T->l=insertTree(T->l,x);
    }else if(x>T->val){  //相同节点直接忽略
        T->r=insertTree(T->r,x);
    }
    return T;
}

//前序遍历
void preOrder(Bitnode* root){
    if(root!=NULL){
        printf("%d ",root->val);
        preOrder(root->l);
        preOrder(root->r);
    }
}

//中序遍历
void inOrder(Bitnode* root){
    if(root!=NULL){
        inOrder(root->l);
        printf("%d ",root->val);
        inOrder(root->r);
    }
}

//后序遍历
void postOrder(Bitnode* root){
    if(root!=NULL){
        postOrder(root->l);
        postOrder(root->r);
        printf("%d ",root->val);
    }
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Bitnode* T=NULL;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            T=insertTree(T,x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}