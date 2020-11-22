#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int manhattan(int a, int b, int x, int y){
    return abs(a-x)+abs(b-y);
}

int main(){
    int N;
    scanf("%d", &N);
    int b[70000][2], i, j, a[70000][2], score=70000;
    for(i=0; i<N; i++){b[i][0]=0; b[i][1]=0; a[i][0]=0; a[i][1]=0;}
    for(i=0; i<N; i++){
        scanf("%d%d", &a[i][0], &a[i][1]);
        if(i!=0){
            for(j=0; j<i; j++){
                if(manhattan(a[i][0],a[i][1],b[j][0],b[j][1]) < score){
                    score = manhattan(a[i][0],a[i][1],b[j][0],b[j][1]);
                }
            }
            printf("%d\n", score);
            score = 70000;
        }
        
        scanf("%d%d", &b[i][0], &b[i][1]);
        for(j=0; j<=i; j++){
            if(manhattan(a[j][0],a[j][1],b[i][0],b[i][1]) < score){
                score = manhattan(a[j][0],a[j][1],b[i][0],b[i][1]);
            }
        }
        printf("%d\n", score);
        score = 70000;
    }
    return 0;
}
 

