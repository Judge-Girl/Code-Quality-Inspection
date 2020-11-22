#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int type,i,j;
    scanf("%d",&type);
    if(type==0){
        char string[100000];
        scanf("%s",string);
        int length=strlen(string);
        int count=0;
        while(1){
            long long int result=0;
            if((length+1)-8>0){
                for(i=7 ; i>=0 ; --i){
                    long long int copy=string[count++];
                    result+=(copy<<(8*i));
                }
                printf("%lld\n",result);
                length-=8;
            }
            else{
                for(i=7 ; i>7-length ; --i){
                    long long int copy=string[count++];
                    result+=(copy<<(8*i));
                }
                printf("%lld\n",result);
                break;
            }
        }
    }
    else{
        int n;
        char result_string[100000];
        int count=0;
        scanf("%d",&n);
        for(i=0 ; i<n ; ++i){
            long long int for_64bits;
            long long int test=255;
            scanf("%lld",&for_64bits);
            for(j=7 ; j>=0 ; --j){
                result_string[count++]=((for_64bits&(test<<(8*j)))>>(8*j));
            }
        }
        result_string[count]='\0';
        printf("%s",result_string);
    }
}

