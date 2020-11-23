#include <stdio.h>
#include <string.h>
char str[100005];
unsigned long long arr[12505] = {};
unsigned long long arr1[12505];
int main(int argc, char const *argv[])
{
    int task;
    scanf("%d", &task);
    if (!task) {
        scanf("%s", str);
        int len = 0;
        int slen = strlen(str);
        int i = 0;
        while (i <= slen) {
            for (int x = 56; x >= 0 && i <= slen; x-=8) {
                arr[len] |= (unsigned long long)str[i++] << x;
            }
            len++;
        }
        for (int i = 0 ; i < len; i++) {
            printf("%llu\n", arr[i]);
        }
    }
    else {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%llu", &arr1[i]);
        }
        int end = 0;
        for (int i = 0; i < N && !end; i++) {
            int cnt = 0;
            while (cnt < 8 && !end) {
                  char ans = (char)(arr1[i] >> (64 - 8));
                  if (ans == '\0') {
                    end = 1;
                    break;
                  }
                  printf("%c", ans);
                  arr1[i] <<= 8;
                  cnt++;
            }
        }
    }
    return 0;
}
