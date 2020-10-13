//二叉排序树，注意根节点初始化和new的用法
// https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3?tpId=69&tqId=29670&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
#include<cstdio>

typedef struct bitNode{
    int val;
    struct bitNode * l;
    struct bitNode * r;
    bitNode(int x): val(x), l(NULL), r(NULL){};
}bitNode;

const int N = 101;

bitNode* insertTree(bitNode* root, int x){
    if(root == NULL){
        root =new bitNode(x);
    }else if(x < root->val){
        root->l = insertTree(root->l, x);
    }else if(x > root->val){
        root->r = insertTree(root->r, x);
    }
    return root;
}

void preOrder(bitNode* root){
    if(root != NULL){
        printf("%d ", root->val);
        preOrder(root->l);
        preOrder(root->r);
    }
}


void inOrder(bitNode* root){
    if(root != NULL){
        inOrder(root->l);
        printf("%d ", root->val);
        inOrder(root->r);
    }
}


void postOrder(bitNode* root){
    if(root != NULL){
        postOrder(root->l);
        postOrder(root->r);
        printf("%d ", root->val);
    }
}

int main(){
    int n, temp;
    while(scanf("%d", &n) != EOF){
        bitNode* root = NULL;   //必须初始化为NULL
        while(n--){
            scanf("%d", &temp);
            root = insertTree(root, temp); 
        }
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
    }
    return 0;
}
