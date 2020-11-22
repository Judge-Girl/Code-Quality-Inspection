#include <stdio.h>
#include <string.h>

char input[100000] ;
int main(){
    int n ;
    scanf("%d" , &n);
    if(n == 0){
        long long int LLI = 0;
        scanf("%s" , input);
        for(int i = 0 ; i < (strlen(input))/8*8+8 ; i++){
            LLI = LLI << 8;
            LLI += input[i];
            if(i % 8 == 7){
                printf("%lld\n" , LLI);
                LLI = 0;
            }
        }
    }
    if(n == 1){
        int m;
        scanf("%d" , &m);
        for(int i = 0 ; i < m ; i++){
            long long int LLI;
            scanf("%lld" , &LLI);
            for(int j = 7 ; j >=0 ; j--){
                input[i*8+j] = LLI << 56 >> 56;
                LLI = LLI >> 8;
            }
        }
        printf("%s\n" , input);
    }

    return 0;
}

