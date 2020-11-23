#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRLN 100000
#define MAXN 12500
#define STRINT 0
#define INTSTR 1

char S[STRLN]={'0'};

void strint(void){
    char *input;
    int f=1;
    int n,i;
    n=0;
    scanf("%s",S);
    long long int wndw=((long long int)1<<8)-1;
    long long int output=0;
    while(f){
        for(i=0;i<8;i++){
            output=output<<8|(S[n*8+i]&wndw);
            if(S[n*8+i]=='\0'){
                output=output<<(8*(7-i));
                f=0;
                break;
            }
        }
        printf("%lld\n",output);
        n++;
    }
    return;
}

void intstr(void){
    int N;
    int n,i;
    char *input;
    scanf("%d",&N);
    for(n=0;n<N;n++){
        input=&S[n*8];
        scanf("%llu",input);
    }
    int f=1;
    n=0;
    while(f){
        for(i=0;i<8;i++){
            if(S[n*8-i+7]=='\0'){
                f=0;
                break;
            }
            printf("%c",S[n*8-i+7]);

        }
        n++;
    }
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    switch (T){
    case STRINT:
        strint();
        break;
    case INTSTR:
        intstr();
        break;
    }

}

