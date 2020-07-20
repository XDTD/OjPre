//大数进制转换，注意最后的do while（0的特殊情况）
//https://www.nowcoder.com/practice/ae4b3c4a968745618d65b866002bbd32?tpId=60&tqId=31034&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<cstring>

const int N = 100000;    //总共最多10000
const int digit = 10000; //4位一组
char s[N];
char ans[N];

struct bigInteger{
    int nums[N];
    int size;


    void set(int x){
        memset(nums,0,sizeof(nums));
        size = 0;
        while(x!=0){
            nums[size++] = x % digit;
            x /= digit;
        }
    }

    void output(){
        for(int i = size-1; i>= 0; i--){
            if(i!=size-1)
                printf("%04d",nums[i]);
            else
                printf("%d",nums[i]);
        }
    }

    bigInteger operator *(int x) const{
        bigInteger ret;
        ret.set(0);
        int next = 0;
        for(int i = 0; i < size; i++){
            int tmp = nums[i] * x + next;
            next = tmp /digit;
            ret.nums[ret.size++] = tmp % digit;
        }
        if(next != 0)
            ret.nums[ret.size++] = next;
        return ret;
    }

    //可以优化
    bigInteger operator + (const bigInteger& A) const{
        bigInteger ret;
        ret.set(0);
        int carry = 0;
        for(int i = 0;i<A.size || i<size; i++){
            int tmp = A.nums[i] + nums[i] + carry;
            carry = tmp / digit;
            ret.nums[ret.size++] = tmp % digit;
        }
        if(carry != 0)
            ret.nums[ret.size++] = carry;
        return ret;
    }

    //大数除以普通整数 x
    bigInteger operator / (int x) const{
        bigInteger ret;
        ret.set(0);
        int reminder = 0;
        for(int i = size-1;i >=0 ; i--){
            int t = (reminder *digit + nums[i]) / x;  
            int r = (reminder *digit + nums[i]) % x;  //余数
            ret.nums[i] = t;
            reminder = r;
        }
        ret.size = 0; //注意初始化
        for(int i = 0;i < N; i++){
            if(ret.nums[i] != 0) 
                ret.size=i + 1;
        }
        return ret;
    }

    int operator % (int x) const{
        int reminder = 0;
        for(int i = size-1;i>=0; i--){
            reminder = (reminder * digit + nums[i]) %x;
        }
        return reminder;
    }

};

int main(){
    int M,N;
    while(scanf("%d %d",&M,&N) != EOF){
        scanf("%s",s);
        bigInteger n;  //转换成的数
        n.set(0);
        bigInteger c;  
        int len = strlen(s);
        for(int i = 0;i < len; i++){
            int tmp;
            if(s[i]>='0' && s[i] <='9')
                tmp = s[i] - '0';
            else
                tmp = s[i] -'A'+10;
            c.set(tmp);
            n = n * M + c;
        }
        int cnt = 0;
        do{
            int t = n %N; //求余数
            if(t>9) ans[cnt++] = t-10+'a';
            else  ans[cnt++] = t + '0';
            n = n / N;
        }while(n.nums[0]!=0);
        for(int i = cnt -1; i>=0 ; i--){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}