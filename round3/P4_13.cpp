//bignum transactions,not skilled
//https://www.nowcoder.com/practice/ae4b3c4a968745618d65b866002bbd32?tpId=60&tqId=31034&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking

#include<cstdio>
#include<cstring>
class bitInterger{
public:
    static const int digit = 10000;
    static const int N = 1000;
    int nums[N]; 
    int size;

    void init(){
        for(int i = 0; i < N; i++){
            nums[i] = 0;
        }
        size = 0;
    }

    void set(int x){
        init();
        do{
            nums[size++] = x % digit;
            x /= digit; 
        }while(x != 0);
    }

    void muitiple(int x){
        int carry = 0;
        for(int i = 0; i < size; i++){
            nums[i] = nums[i] * x + carry;
            carry = nums[i] / digit;
            nums[i] %= digit;
        }
        if(carry != 0){
            nums[size++] = carry;
        }
    }

    void add(int x){
        int carry = x;
        for(int i = 0; i < size ; i++){
            nums[i] += carry;
            carry = nums[i] / digit;
            nums[i] %= digit;
            if(carry == 0) break;
        }
        if(carry != 0){
            nums[size++] = carry;
        }
    }

    void division(int x){
        int reminder = 0;
        for(int i = size-1; i >=0; i--){
            int t = (reminder * digit + nums[i]) / x;
            int r = (reminder * digit + nums[i]) % x;
            nums[i] = t;
            reminder = r;
        }
    }

    int getReminder(int x){
        int reminder = 0;
        for(int i = size-1; i >=0; i--){
            reminder = (reminder * digit + nums[i]) % x;
        }
        return reminder;
    }    
};

int str2num(char c){
    return c <= 'Z'&& c >= 'A' ? c - 'A' + 10 : c - '0'; 
}

char num2str(int x){
    return x >= 10? x - 10 + 'a' : x + '0';
}

int main(){
    int M,N;
    while(scanf("%d %d", &M, &N) != EOF){
        char tmp[10000];
        scanf("%s", tmp);
        int len = strlen(tmp);
        bitInterger x;
        x.set(0);
        for(int i = 0; i < len; i++){
            int cur = str2num(tmp[i]);
            x.muitiple(M);
            x.add(cur);
        }
        int j = 0;
        do{
            int cur = x.getReminder(N);
            tmp[j++] = num2str(cur);
            x.division(N);
        }while(x.nums[0] != 0);
        while(j--){
            printf("%c", tmp[j]);
        }
        printf("\n");
    }
    return 0;
}
