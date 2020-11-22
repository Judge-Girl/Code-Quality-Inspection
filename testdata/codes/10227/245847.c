#include <stdio.h>
#include <string.h>
#define MAX 100000
char integer[MAX][8];
char input[MAX];
unsigned long long int to_be_print_0[MAX] = {0};
char to_be_print_1[MAX];
int main()
{
    unsigned long long int input_1;
    unsigned long long int cmp = 255;
    cmp <<= 56;
    int type;
    int i,j;
    scanf("%d", &type);
    int number_of_string = 0;
    if(type) scanf("%d",&number_of_string);
    int m = 0;
    for(i = 0; i <= number_of_string; i++){
        if(!type){
            scanf("%s",input);
            int k = 0;
            int l = 0;
            while(k <= strlen(input)/8){
                for(j = 0; j < 8; j++){
                    to_be_print_0[k]<<=8;
                    to_be_print_0[k]+=input[l++];
                }
                printf("%llu\n",to_be_print_0[k]);
                k++;
            }
        }
        else{
            scanf("%llu",&input_1);
//            printf("%llu\n",input_1);
            for(j = 0; j < 8 ; j++){
                unsigned long long int temp = (input_1&cmp);
                to_be_print_1[m++] = temp>>=56;
                input_1<<=8;
//                printf("%c\n",to_be_print_1[m-1]);
            }
        }
    }
    if(type) printf("%s",to_be_print_1);
    return 0;
}

