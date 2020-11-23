#include <stdio.h>
#include <stdlib.h>
int abs(int x) {
    return x < 0 ? -x : x;
}
int main() {
    int N;
    scanf("%d", &N);

    int num[2] = {0};
    int map[2][30001][2];
    for (int i = 0; i < 2 * N; i++) {
        int p = i % 2, d = p ^ 1;
        scanf("%d%d", &map[p][num[p]][0], &map[p][num[p]][1]);
        if(i == 0) {
            num[p]++;
            continue;
        }
        int mindis = 65535;
        for (int j = 0; j < num[d]; j++) {
            int dis = abs(map[p][num[p]][0] - map[d][j][0]) + abs(map[p][num[p]][1] - map[d][j][1]);
            if(dis < mindis) {
                mindis = dis;
            }
        }
        printf("%d\n", mindis);
        num[p]++;
    }
    return 0;
}
