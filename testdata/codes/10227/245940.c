#include <stdio.h>
#include <string.h>
 
int main()
{
    int T, N;
    scanf("%d", &T);
    char s[100000];
    long long b[12500];
    if ( T ) {
        scanf("%d", &N);
        memset(s, 0, sizeof(s));
        for ( int i = 0; i < N; i++) {
            scanf("%lld", &b[i]);
            for ( int j = 0; j < 8; j++) {
                s[i * 8 + j] |= b[i] >> (8 * (7 - j));
            }
        }
        printf("%s\n", s);
    } else {
        scanf("%s", s);
        for ( int i = 0; i < 1000; i++)
            b[i] = 0LL;
        int cnt = 0, bc = 0;
        for ( int i = 0; s[i] != '\0'; i++) {
            b[cnt] |= (long long)s[i];
            bc++;
            if ( bc == 8 ) {
                bc = 0;
                cnt++;
            } else {
                b[cnt] <<= 8;
            }
        }
        if ( bc != 7 )
            b[cnt] <<= 8 * (7 - bc);
        for ( int i = 0; i <= cnt; i++)
            printf("%lld\n", b[i]);
    }
    return 0;
}
