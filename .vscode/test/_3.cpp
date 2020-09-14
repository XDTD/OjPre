#include<cstdio>
#include<cstring>

typedef struct node{
    int val;
    struct node * l;
    struct node * r;
    node(int x): val(x),l(NULL),r(NULL){};
}node;

void preOrder(node * root){
    if(root != NULL){
        printf("%d ",root ->val);
        preOrder(root->l);
        preOrder(root->r);
    }
}

void inOrder(node * root){
    if(root != NULL){
        inOrder(root->l);
        printf("%d ",root ->val);
        inOrder(root->r);
    }
}

void afterOrder(node * root){
    if(root != NULL){
        afterOrder(root->l);
        afterOrder(root->r);
        printf("%d ",root ->val);
    }
}

node * findTree(node * T,int x){
    if(T!=NULL){
        if(T->val == x)
            return T;
        else{
            node * tmp1 = findTree(T->l,x);
            if(tmp1 != NULL ) 
                return tmp1;
            node *tmp2 = findTree(T->r,x);
            if(tmp2 != NULL ) 
                return tmp2;
        } 
    }
    return NULL;
}



int main(){
    int n,x;
    while(scanf("%d %d",&n,&x) != EOF && n != 0){
        node * root = new node(x);
        while(n--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            node * T = findTree(root,a);
            if(b != 0) T->l = new node(b);
            if(c != 0) T->r = new node(c);
        }
        preOrder(root);
        printf("\n");
        
        inOrder(root);
        printf("\n");
        
        afterOrder(root);
        printf("\n");
    }
    return 0;
}