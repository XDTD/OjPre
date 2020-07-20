//数制转换，注意格式（A,B,C,D字符输出）
//https://www.nowcoder.com/practice/8ef02ef8571b417d8c311a87861f7a03?tpId=61&tqId=29528&tPage=2&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
const int N=20;

int main(){
    int a,b;
    char str[N];
    while(scanf("%d %s %d",&a,str,&b) != EOF){
        long long tmp = 0;
        int len = strlen(str);
        for(int i = 0;i <len;i++){
            if(str[i] >= '0'&&str[i] <= '9'){
                tmp = tmp*a + str[i]-'0';
            }else if(str[i] >='a' && str[i] <= 'f'){
                tmp = tmp*a + str[i]-'a'+10;
            }else{
                tmp = tmp*a + str[i]-'A'+10;
            }
        }
        int cnt=0;
        while(tmp!=0){   //格式问题！！！！
            if(tmp%b>=10){
                str[cnt++]=tmp%b-10+'A';
            }else{
                str[cnt++]=tmp%b+'0';
            }
            tmp/=b;
        }
        for(int i=cnt-1;i>=0;i--){
            printf("%c",str[i]);
        }
        printf("\n");
        memset(str,0,N);
    }
    return 0;
}