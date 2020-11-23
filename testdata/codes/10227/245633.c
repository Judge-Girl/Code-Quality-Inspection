#include <stdio.h>
#include <string.h>

void printbin(unsigned long long a){
    for(int i = 63; i>=0; i--){
        if((a>>i) &1) printf("1");
        else printf ("0");
    }
    puts("");
}
int main(){
    int type;
    char string[100000] = { 0 };
    unsigned long long result;
    scanf("%d",&type);
    if(type==0){
        result = 0;
        scanf("%s",string);
        int t = strlen(string);
        for(int j = 0; j < t; j = j+8){
            result = 0;
            for(int i = 0; i <8; i++){
                result |= (unsigned long long)string[j+i] << (56-8*i);
            }
            printf("%llu\n",result);
        }
        if(t%8==0) printf("0");
    }
    else{
        int n;
        scanf("%d",&n);
        unsigned long long input[n];
        for(int i = 0; i<n; i++){
            scanf("%llu",&input[i]);
            unsigned char output[16];
            for(int j = 0; j <64; j = j+8){
                output[7 - (j/8)] = input[i] >> j;
            }
            output[8] = '\0';
            printf("%s",output);
        }
    }
    return 0;
}
