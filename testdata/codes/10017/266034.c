#include <stdio.h>
#include <stdlib.h>
int s[2][50000][2], count[2];

int dis(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(void){
    int n;
    scanf("%d%d%d", &n, &s[0][0][0], &s[0][0][1]);
    count[0] = 1, count[1] = 0;
    for(int i = 1; i < 2 * n; i++){
        scanf("%d%d", &s[i % 2][count[i % 2]][0], &s[i % 2][count[i % 2]][1]);
        int min = 2 * 32768;
        for(int j = 0; j < count[(i + 1) % 2]; j++){
            int d = dis(s[i % 2][count[i % 2]][0], s[i % 2][count[i % 2]][1], s[(i + 1) % 2][j][0], s[(i + 1) % 2][j][1]);
            if(d < min) min = d;
        }
        count[i % 2]++;
        printf("%d\n", min);
    }
    return 0;
}

