//https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce?tpId=40&&tqId=21544&qru=/ta/kaoyan/question-ranking
//从二叉树的前序中序看后序
#include<cstdio>
#include<cstring>
#include<malloc.h>
using namespace std;


typedef struct bitNode{
    char val;
    struct bitNode *l;
    struct bitNode *r;
    bitNode(char x) : val(x), l(NULL), r(NULL){};
}bitNode;

const int N = 21;
char s1[N];
char s2[N];
int curIdx1, curIdx2;

bitNode* creatTree(int l1, int r1, int l2, int r2){
    if(l1 > r1)    
        return NULL;
    bitNode* root = (bitNode*)malloc(sizeof(bitNode));
    root->val = s1[l1];
    int rootIdx = l1;
    for(int i = l2; i <= r2; i++){  //结尾是小于等于，遍历所有字符串
        if(s2[i] == s1[l1]){
            rootIdx  = i;
            break;
        }
    }
    root->l = creatTree(l1+1, rootIdx-l2+l1, l2, rootIdx-1);  //有个相对偏移，保持长度一致
    root->r = creatTree(rootIdx+1-r2+r1, r1, rootIdx+1, r2);  
    return root;
}

void postOrder(bitNode* root){
    if(root != NULL){
        postOrder(root->l);
        postOrder(root->r);
        printf("%c", root->val);
    }
}
int main(){
    while(gets(s1)){
        gets(s2);
        bitNode* root = creatTree(0, strlen(s1)-1, 0, strlen(s2)-1);
        postOrder(root);
        printf("\n");
    }
    return 0;
}
