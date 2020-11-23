#include <stdio.h>
#include <string.h>
 
int main(){
    int type, k;

    unsigned long long int ULLI=0;
    unsigned int UI;
    unsigned short US;
    char s[9];
    scanf("%d", &type);
    if(type==0){
        char string[100001]; 
        scanf("%s", string);
        int len;
        len=strlen(string);
        //printf("%d", len);
        int count=0;
        for(int i=0; i<len/8+1;i++){
            //printf("%d\n",i);
            for(int j=0; j<8; j++) {

            ULLI<<=8;
            ULLI|=string[i*8+j]; 

               

            

            }   
           printf("%llu\n", ULLI); 
           ULLI=0;
        }       
    }
    if(type==1){
        int num;
        char str[100001];
        unsigned long long int ULL[12500];
        scanf("%d", &num);
        for(int i=0 ; i<num; i++){
            scanf("%llu", &ULL[i]);
        }
        for(int j=0; j<num; j++){



            for(int i=j*8+7; i>=j*8; i--){



                str[i]=ULL[j]&0xff;
                ULL[j]>>=8;
            }
        } 
        printf("%s", str);
        

        


            //str[i]==ULLI&0xff;
           // ULLI>>=8;
       
 
    }
 
 
    return 0;
}
