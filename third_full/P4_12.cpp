//低级大数乘法
//https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=60&tqId=29496&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking

#include<cstdio>
#include<cstring>


class bigInterger{
public:
    static const int digit = 10000;
    static const int N = 1000;
    int size;
    int num[N];

    void init(){
        memset(num, 0, sizeof(num));
        size = 0;
    }

    void bigIntergerMultiple(int n){
        init();
        num[0] = 1;
        size = 1;
        for(int i = 2; i <= n; i++){
            int next = 0, j = 0;
            do{
                num[j] = num[j] * i + next;
                next = num[j] / digit;
                num[j] %= digit;
                j++;
            }while(next != 0 || j < size);
            size = j;
        }
    }

    void output(){
        for(int i = size - 1; i >= 0; i--){
            if(i == size - 1) 
                printf("%d", num[i]);
            else
                printf("%04d", num[i]);
        }
    }

};


int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        bigInterger ans;
        ans.bigIntergerMultiple(n);
        ans.output();
    }
    return 0;
}


