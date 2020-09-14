#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

struct bigInterger{
    int nums[40];
    int size;
};

bigInterger  add(bigInterger a,bigInterger b){
    if(a.size >= b.size){
        int flag = 0, i;
        for(i = 0; i < a.size || flag !=0; i++){
            a.nums[i] = a.nums[i]+ b.nums[i] + flag;
            a.nums[i]  %= 1000;
            flag = a.nums[i] /1000;
            a.size = max(a.size,i+1);
        }
    }else{
        return add(b, a);
    }
    return a;
}

bigInterger quyu(bigInterger a){
    for(int i = a.size; i < a.size;i++){
        
    }
}

int Fibo(int n){
    if(n == 1 || n == 2) return 1;
    else
        return Fibo(n-1) + Fibo(n-2);
}

int getSum(int n) {
    int ans = 0;
    for(int i = 1;i <=n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1;k <= j; k++){

            }
        }
    }
}