//二叉树的建立，一次过，注意单一出口时的malloc和指针不熟练
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&tqId=29483&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<algorithm>

typedef struct bitNode{
    char val;
    struct bitNode *l;
    struct bitNode *r;
    bitNode(char x) : val(x), l(NULL), r(NULL){};
}bitNode;

const int  N = 101;
char s[N];
int curIdx;

bitNode* createTree(){
    char val = s[curIdx++];
    bitNode* root;
    if(val == '#') 
        root = NULL;
    else{
        root = (bitNode*)malloc(sizeof(bitNode));
        root->val = val;
        root->l = createTree();
        root->r = createTree();
    }
    return root;
}

void inOrder(bitNode* root){
    if(root != NULL){
        inOrder(root->l);
        printf("%c ",root->val);
        inOrder(root->r);
    }
}

int main(){
    while(scanf("%s", s) != EOF){
        curIdx = 0;
        bitNode* root = createTree();
        inOrder(root);
        printf("\n");
    }
    return 0;
}