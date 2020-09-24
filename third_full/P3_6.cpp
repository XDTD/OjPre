//二叉搜索树
//https://www.nowcoder.com/practice/3d6dd9a58d5246f29f71683346bb8f1b?tpId=63&tqId=29571&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking


#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

typedef struct bitNode{
    int val;
    struct bitNode * l;
    struct  bitNode* r;
    bitNode(char x): val(x), l(NULL), r(NULL){};
}bitNode;

string pre,pre2cmp;
string in,in2cmp;
string temp;
bitNode* insertTree(bitNode* root, int x){
    if(root == NULL){
        root = new bitNode(x);
    }else if(x < root->val){
        root->l = insertTree(root->l, x);
    }else if(x > root->val){
        root->r = insertTree(root->r, x);
    }
    return root;
}

void preOrder(bitNode* root){
    if(root != NULL){
        temp.push_back(root->val);
        preOrder(root->l);
        preOrder(root->r);
    }
}

void inOrder(bitNode* root){
    if(root != NULL){
        inOrder(root->l);
        temp.push_back(root->val);
        inOrder(root->r);
    }
}


int main(){
    int n;
    while(cin >> n && n != 0){
        string oral = "";
        cin >> oral;
        bitNode* root = NULL;
        for(int i = 0; i < oral.size(); i++){
            root = insertTree(root, oral[i]-'0');
        }
        temp = ""; preOrder(root); pre = temp;
        temp = ""; inOrder(root); in = temp;
        while(n--){
            oral = "";
            cin >> oral;
            root = NULL;
            for(int i = 0; i < oral.size(); i++){
                root = insertTree(root, oral[i]-'0');
            }
            temp = ""; preOrder(root); pre2cmp = temp;
            temp = ""; inOrder(root); in2cmp = temp;
            if(pre2cmp == pre && in2cmp == in)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
