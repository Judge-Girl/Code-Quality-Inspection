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
        int i;
        if(m==0){
            i = 0;
            t1 = 0;
        }
        else{
            i = start[m-1] + 1;
            t1 = start[m-1]+1;
        }
        t2 = start[m];
        for(int j=0;j<i; j++){
            printf("+");
        }
        for(;i<=start[m];i++){
            printf("%c",string[i]);
        }
        for(int j = i; j<l; j++){
            printf("+");
        }
        puts("");
        if(n==0){
            i = 0;
            t3 = 0;
        }
        else{
            i = start[n-1] + 1;
            t3 = i;
        }
        for(int j=0;j<i; j++){
            printf("+");
        }
        for(;i<=start[n];i++){
            printf("%c",string[i]);
        }
        for(int j = i; j<l; j++){
            printf("+");
        }
        t4 = start[n];
        puts("");
        for(int p=0; p<l; p++){
            if((p>=t1&&p<=t2)||(p>=t3&&p<=t4)){
                printf("+");
            }
            else printf("%c",string[p]);
        }
        puts("");
    }
    return 0;
}
