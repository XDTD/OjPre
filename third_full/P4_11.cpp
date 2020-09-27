#include<cstdio>
#include<cstring>
class bigInterger{
    public:
        static const int N = 10000; //四位应该是10000不是1000
        static const int NofDigits = 1000;
        int digit[1000];
        int size;

    void init(){
        for(int i = 0; i < NofDigits; i++){
            digit[i] = 0;
        }
        size = 0;
    }

    void set(char s[]){
        init();
        int len = strlen(s);
        int n = len / 4;
        int m = len % 4;
        size = n + 1;
        for(int i = n ; i >= 0; i--){
            if(i == 0){
                //m == 0不用赋值，否则多一个
                if(m == 1) sscanf(s+4*i, "%1d", &digit[n-i]);
                else if(m == 2) sscanf(s+4*i, "%2d", &digit[n-i]);
                else if(m == 3) sscanf(s+4*i, "%3d", &digit[n-i]);
            }
            else sscanf(s+4*(i-1)+m, "%4d", &digit[n-i]);  //赋值公式需要反复推敲
        }
    }

    void output(){
        for(int i = size - 1; i >= 0; i--){
            if(i != size - 1) 
                printf("%04d",digit[i]);
            else
                printf("%d", digit[i]);
        }
        printf("\n");
    }

    bigInterger add(bigInterger a){
        bigInterger ans;
        ans.init();
        int carry = 0;
        for(int i = 0; i < a.size || i < size; i++){
            if(i == 186)
                int aaa = 1;
            int temp = digit[i] + a.digit[i] + carry;
            if(temp > 0){   //最后一位注意size可能超一个
                ans.digit[ans.size++] = temp % N;
                carry = temp / N;
            }
        }
        if(carry != 0){
            ans.digit[ans.size++] = carry;
        }
        return ans;
    }

};

int main(){
    char s1[1002], s2[1002];
    bigInterger a, b, c;
    while(scanf("%s %s", s1, s2) != EOF){
        a.set(s1);
        b.set(s2);
        c = a.add(b);
        c.output();
    }
    return 0;
}