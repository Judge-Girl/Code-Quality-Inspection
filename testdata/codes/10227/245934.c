#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[100000]={0};
long long n[12500]={0};
void int_to_string(char s[], long long n[]){
    int len=strlen(s)+1;
    int i,j;
    int use=len/8;
    for(i=0; i<len; i++){
        n[i/8]<<=8;
        n[i/8]|=s[i];
        //printf("%lld\n",n[i/8]);
    }
    if(len%8){
        n[len/8]<<=(8-len%8)*8;
        use++;
    }
    for(i=0; i<use; i++){
        printf("%lld\n",n[i]);
    }
}
void string_to_int(char s[], long long n[], int num){
    int i=0,j=0;
    int count=0;
    unsigned long long top=255;
    top<<=56;
    //printf("top=%llu\n",top);
    /*for(i=0; i<num; i++)
        printf("%lld\n",n[i]);*/
    for(i=0; i<num; i++){
        for(j=0; j<8; j++){
            s[count]=(top & n[i])>>56;
            //printf("%c ",s[count]);
            n[i]<<=8;
            count++;
        }
    }
    printf("%s",s);
}
int main()
{
    int type=0;
    scanf("%d",&type);
    int i;
    if(type){
        int num;
        scanf("%d",&num);
        for(i=0; i<num; i++)
            scanf("%lld",&n[i]);
        string_to_int(s,n,num);
    }
    else{
        scanf("%s",s);
        int_to_string(s,n);
    }
    return 0;
}

