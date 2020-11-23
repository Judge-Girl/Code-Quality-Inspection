#include <stdio.h>
#include <string.h>

int main(){
        int cmd;
        scanf("%d", &cmd);
        if(cmd){ //long long to string
                int n;
                scanf("%d", &n);
                long long int in;
                for(int i = 0; i < n; i++){
                        char str[9] = {'\0'};
                        scanf("%lld", &in);
                        for(int j = 0; j < 8; j++){
                                str[j] |= (in >> 8*(7-j));
                        }
                        printf("%s", str);
                }
                printf("\n");
        }
        else{
                char in[100000];
                scanf("%s", in);
                long long int out = 0;
                for(int i = 0; i < strlen(in); i++){
                        out |= (((long long)in[i]) << 8*(7-i%8));
                        if(i % 8 == 7){
                                printf("%lld\n", out);
                                out = 0;
                        }
                }
                printf("%lld\n", out);
                out = 0;
        }
}

