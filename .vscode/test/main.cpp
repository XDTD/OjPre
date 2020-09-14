#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int nums1[2][3],nums2[3][2];
    while(scanf("%d %d %d",&nums1[0][0],&nums1[0][1],&nums1[0][2]) != EOF){
        scanf("%d %d %d",&nums1[1][0],&nums1[1][1],&nums1[1][2]);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                scanf("%d",&nums2[i][j]);
            }
        }
        int ans[2][2];
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int ii = 0;ii <3;ii++){
                    ans[i][j] += nums1[i][ii] * nums2[ii][j];
                }
            }
        }
        printf("%d ",ans[0][0]);
        printf("%d \n",ans[0][1]);
        printf("%d ",ans[1][0]);
        printf("%d ",ans[1][1]);
    }

    return 0;
}