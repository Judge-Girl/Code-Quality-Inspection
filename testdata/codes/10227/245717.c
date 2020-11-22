#include <stdio.h>
#include <string.h>

#define MAXLEN 100010
#define MAXN 12510

typedef long long int lli;

// for debug usage
void print_binary(lli num){
    char buffer[65] = {0};
    for(int i=0; i<64; i++){
        buffer[63-i] = (num & 1)? '1' : '0';
        num >>= 1;
    }
    printf("%s\n", buffer);
}

lli str2lli(char *str){
    lli ans=0;
    for(int i=0; i<8; i++){
        ans += str[i];
        //print_binary(ans);
        if(i != 7) ans <<= 8;
    }
    return ans;
}
void str2int(){
    char str[MAXLEN] = {0};
    scanf("%s", str);
    char *ptr = str;
    while(*ptr != '\0'){
        printf("%lld\n", str2lli(ptr));
        ptr += 8;
    }
    if(strlen(str)%8==0) printf("0\n");
}

void print_lli(lli num){
    char buffer[9]={0};
    for(int i=0; i<8; i++){
        buffer[7-i] = num & 127;
        num >>= 8;
    }
    printf("%s", buffer);
}
void int2str(){
    int N;
    scanf("%d", &N);
    while(N--){
        lli num;
        scanf("%lld", &num);
        print_lli(num);
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    if(T == 0) str2int();
    if(T == 1) int2str();

    return 0;
}
