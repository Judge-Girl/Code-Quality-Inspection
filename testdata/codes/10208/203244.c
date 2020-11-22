/*input
10
20
5
15
10
*/
#include <stdio.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
inline int rit(){
    int res = 0;
    int val = 1;
    char c = getchar();
    while(!(c >= '0' && c <= '9')){
        val = c == '-' ? -1 : val;
        c = getchar();
    }
    while((c >= '0' && c <= '9')) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res * val;
}
int main(){
    int a = rit() , b = rit() , h = rit() , c = rit() , d = rit();
    int v1 = a * b * h / (a * b - c * d);
    printf("%d\n", v1);
    return 0;
}
