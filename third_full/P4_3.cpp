//进制转换，注意输入大小写混用
//https://www.nowcoder.com/practice/8ef02ef8571b417d8c311a87861f7a03?tpId=61&tqId=29528&tPage=2&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking
#include<cstdio>
#include<cstring>

const int N = 200;

int char2num(char c){
    int ans;
    if(c <= '9' && c >= '0')
        ans = c - '0';
    else if (c >= 'a' &&c <= 'z')
        ans = c - 'a' + 10;
    else
        ans = c -'A' + 10;
    return  ans;
}

char num2char(int x){
    return x>=0 && x<10 ? x+'0' : x-10+'A';
}

int main(){
    int n, b;
    char charOfN, charOfB, s1[N], s2[N];
    while(scanf("%d %s %d", &n, s1, &b) !=  EOF){
        long long temp = 0;
        //转化为十进制
        int lenOfA = strlen(s1), factor = 1;
        for(int i = lenOfA - 1; i >= 0; i--){
            temp += factor*char2num(s1[i]);
            factor *= n;
        }
        //转为目标进制
        int i = 0;
        do{
            s2[i++] = num2char(temp % b);
            temp /= b;
        }while(temp!=0);
        //输出
        while(i--){
            printf("%c", s2[i]);
        }
        printf("\n");
    }
    return 0;
}