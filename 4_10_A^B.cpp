//人见人爱 A^B，注意二分幂的循环写法
//http://acm.hdu.edu.cn/showproblem.php?pid=2035
#include<cstdio>

//二分幂,循环写法
int binPower(int A,int B){
    int ans = 1;
    while(B!=0){
        if(B%2 == 1){
            ans = ans * A; 
            ans = ans % 1000;
        }
        A *= A;
        A %= 1000;
        B /= 2;
    }
    return ans;
}


int main(){
    int A,B;
    while(scanf("%d %d",&A, &B) != EOF && (A!=0 || B!=0)){
        int ans=binPower(A,B);
        printf("%d\n",ans); 
    }
    return 0;
}