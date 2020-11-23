#include <stdio.h>
#include <string.h>

int main(){
    char string[10000];
    int start[10000] = { 0 };
    int m,n;
    int t1,t2,t3,t4;
    while(scanf("%s%d%d",string,&m,&n)==3){
        int sid = 0;
        int l = strlen(string);
        for(int i=0; i<l; i++){
            if(string[i]=='a'||string[i]=='e'||string[i]=='o'||string[i]=='i'||string[i]=='u'){
                start[sid++] = i;
            }
        }
        if(m==0){
            t1 = 0;
        }
        else{
            t1 = start[m-1]+1;
        }
        t2 = start[m];
        for(int j=0;j<t1; j++){
            printf("+");
        }
        for(int i = t1;i<=t2;i++){
            printf("%c",string[i]);
        }
        for(int j = t2+1; j<l; j++){
            printf("+");
        }
        puts("");
        if(n==0){
            t3 = 0;
        }
        else{
            t3 = start[n-1] + 1;
        }
        t4 = start[n];
        for(int j=0;j<t3; j++){
            printf("+");
        }
        for(int i = t3;i<=t4;i++){
            printf("%c",string[i]);
        }
        for(int j = t4+1; j<l; j++){
            printf("+");
        }
        puts("");
        for(int i=0; i<l; i++){
            if((i>=t1&&i<=t2)||(i>=t3&&i<=t4)){
                printf("+");
            }
            else printf("%c",string[i]);
        }
        puts("");
    }
    return 0;
}
