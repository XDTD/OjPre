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
    if(l1 == r1)    
        return NULL;
    bitNode* root = (bitNode*)malloc(sizeof(bitNode));
    root->val = s1[l1];
    int rootIdx = l1;
    for(int i = l2; i < r2; i++){
        if(s2[i] == s1[l1]){
            rootIdx  = i;
            break;
        }
    }
    root->l = creatTree(1, rootIdx, 0, rootIdx);
    root->r = creatTree(rootIdx+1, r1, rootIdx+1, r2);
    return root;
}

void postOrder(bitNode* root){
    if(root != NULL){
        postOrder(root->l);
        postOrder(root->r);
        printf("%c ", root->val);
    }
}
int main(){
    while(gets(s1)){
        gets(s2);
        bitNode* root = creatTree(0, strlen(s1), 0, strlen(s2));
        postOrder(root);
    }
    return 0;
}
