//开的内存太大本地跑不了。。
//注意偏移，i--不是i++
//http://acm.hdu.edu.cn/showproblem.php?pid=1425
#include<cstdio>
#include<cstring>
const int N = 1000001;

int main(){
    int nums[N];
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 0; i < N; i++){
            nums[i] = 0;
        }
        int temp;
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            nums[temp + 500000]++;
        }
        for(int i = N - 1;i >= 0 && m > 0;i--){
            while(nums[i] > 0 && m > 0){
                printf("%d", i - 500000);
                nums[i] --;
                m --;
                if(m != 0) 
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}