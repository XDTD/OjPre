//素数判定
//https://www.nowcoder.com/questionTerminal/a60fe69c1a6d45419f4c4bec8bc8790e
#include<cstdio>
#include<math.h>


bool judge(int x){
    if(x<=1)    
        return false;
    int bound=sqrt(x)+1;
    for(int i=2;i<bound;i++){
        if(x%i == 0) 
            return false;
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(judge(n))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}