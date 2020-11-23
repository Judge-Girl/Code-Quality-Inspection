#include <stdio.h>
#include <stdlib.h>

main(){
    int N;
    int i, j;

    scanf("%d", &N);
    int A1[N*2+5], A2[N*2+5], Manh[N*2+5];
    int min = 2*N+5;
    Manh[min]= 1000000;

    for(i = 0; i < 2 * N; i++){
        scanf("%d", &A1[i]);
        scanf("%d", &A2[i]);
    }

    for(i = 1; i < 2 * N; i++){
        for(j = 0; j < 2*N; j++){
            Manh[j] = 1000000;
        }
        if(i % 2 == 0){
            for(j = 1; j < i; j+=2){
                Manh[j] = abs(A1[i]-A1[j])+abs(A2[i]-A2[j]);
            }
            for(j = 1; j < i; j+=2){
                if(Manh[j] < Manh[min]){
                    min = j;
                }
            }
            printf("%d\n", Manh[min]);
        }
        else if(i % 2 != 0){
            for(j = 0; j < i; j+=2){
                Manh[j] = abs(A1[i]-A1[j])+abs(A2[i]-A2[j]);
            }
            for(j = 0; j < i; j+=2){
                if(Manh[j] < Manh[min]){
                    min = j;
                }
            }
            printf("%d\n", Manh[min]);
        }
    }

    return 0;
}

