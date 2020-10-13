//二叉树遍历，从先序建立二叉树然后中序遍历
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&tqId=29483&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+5; 
int pos;
char str[N];
typedef struct BitNode{
    char val;
    struct BitNode* l;
    struct BitNode* r;
    BitNode(char c):val(c),l(NULL),r(NULL){};
}BitNode;

//建立二叉树
BitNode* createTree(){
    char c=str[pos++];
    if(c=='#') return NULL;
    
    BitNode* root=new BitNode(c);
    root->l=createTree(); //左子树
    root->r=createTree(); //右子树
    return root;
}

//中序遍历
void inorder(BitNode* root){
    if(!root) return ;
    inorder(root->l);
    printf("%c ",root->val);
    inorder(root->r);
}

int main(){
    while(scanf("%s",str)!=EOF){
        pos=0;
        BitNode* root= createTree();
        inorder(root);
        printf("\n");
    }
    return 0;
}