#include <stdio.h>
#include <string.h>
#define maxn 100000

char s[maxn];
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
int l[maxn], r[maxn];
int pr[maxn];

int vl(char c) {
    for (int i = 0; i < 5; ++i)
        if (vowel[i] == c) return 1;
    return 0;
}

int main() {
    while (scanf("%s", s) != EOF) {
        int x, y; scanf("%d%d", &x, &y);
        int n = strlen(s);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vl(s[i])) continue;
            int j = i - 1;
            while (j >= 0 && !vl(s[j])) --j;
            l[cnt] = j + 1, r[cnt] = i;
            ++cnt;
        }
        for (int i = 0; i < n; ++i) pr[i] = 0;
        for (int i = 0; i < l[x]; ++i) putchar('+');
        for (int i = l[x]; i <= r[x]; ++i) putchar(s[i]), pr[i] = 1;
        for (int i = r[x] + 1; i < n; ++i) putchar('+');
        puts("");
        for (int i = 0; i < l[y]; ++i) putchar('+');
        for (int i = l[y]; i <= r[y]; ++i) putchar(s[i]), pr[i] = 1;
        for (int i = r[y] + 1; i < n; ++i) putchar('+');
        puts("");
        for (int i = 0; i < n; ++i) {
            if (!pr[i]) putchar(s[i]);
            else putchar('+');
        }
        puts("");
    }
    return 0;
}

