#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#define ull unsigned long long int
char str[100010];
ull ullarray[12510] = {0};
int main(void)
{

    int type;
    int N;
    scanf("%d", &type);
    if(type == 0){ // convert string into 64bit
        scanf("%s", str);
        int len = strlen(str);
        int num_of_ull = len / 8 + 1;
        for(int i = 0; i < num_of_ull; i++){
            for(int j = i * 8; j <= i * 8 + 7; j++){
                ullarray[i] = ((ullarray[i] << 8) | (ull)(str[j]));
            }
            printf("%lld\n", ullarray[i]);
        }
    }
    else{ // type == 1, convert 64 bit into string
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%lld", &ullarray[i]);
        int idx = 0;
        for(int i = 0; i < N; i++){
            for(int j = 56; j >= 0; j-= 8){
                if(((ullarray[i] >> j) & 0xff) != 0)
                    str[idx++] = (char)(ullarray[i] >> j);
            }
        }
        str[idx] = '\0';
        printf("%s\n", str);
    }
    return 0;
}

