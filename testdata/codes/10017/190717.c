#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Pair{
    int x, y;
}P;
int min(int x, int y){return (x < y) ? x : y;}
int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    struct Pair arr[2][n];
    int cnt[2] = {};
    for(int i = 0; i < 2 * n; i++){
        struct Pair p; scanf("%d%d", &p.x, &p.y);
        arr[i % 2][cnt[i % 2]] = p;
        cnt[i % 2]++;
        int ans = INT_MAX;
        for(int j = 0; j < cnt[!(i % 2)]; j++){
            ans = min(ans, abs(p.x - arr[!(i % 2)][j].x) + abs(p.y - arr[!(i % 2)][j].y));
        }
        if(i > 0) printf("%d\n", ans);
    }
    return 0;
}
