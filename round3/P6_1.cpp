#include<cstdio>

int main(){
    int x, y, z;
    for(int x = 0; x <= 20; x++){
        for(int y = 0; 3*y <= 100 - x * 5; y++){
                printf("%d %d %d\n", x, y, (100 - x*5 - y*3)*3);
        }
    }
    return 0;
}