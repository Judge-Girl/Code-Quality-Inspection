#include<stdio.h>
void printbinary(unsigned long long int n){
    unsigned long long int check;
    int i = 0;
    for(i = 1; i <= 64; i++){
        check = (long long) 1 << (64 - i);
        printf(check & n? "1":"0");
        if(i%8 == 0) printf(" ");
    }
    printf("\n");
}

unsigned long long int allone = 0;
void makeallone(int n){
    allone &= (long long) 0;
    int i = 0;
    for(i = 0; i < n; i++){
        allone = allone << 1;
        allone = allone | (long long) 1;
        //printf("allone = ");
        //printbinary(allone);
    }
}
int main(void){
    unsigned long long int memory[100000];
    int type;
    char string[100000];
    scanf("%d", &type);
    if(type == 0){
        scanf("%s", string);
        int quotienttemp;
        int remaindertemp;
        unsigned long long int temp = (unsigned long long) 0;
        int i = 0;
        while(string[i] != '\0'){
            //printf("i = %d\n", i);
            int quotient = i / 8;
            quotienttemp = quotient;
            int remainder = i % 8;
            remaindertemp = remainder;
            //printf("q = %d\n", quotient);
            //printf("r = %d\n", remainder);
            //printf("shift = %d\n", (64 - (remainder*8)));
            temp = (unsigned long long) 0;
            temp |= (unsigned long long) string[i] << (64 - 8 - (remainder*8));
            //printf("temp = ");
            //printbinary(temp);
            memory[quotient] |= temp;  
            //printf("memo = ");
            //printbinary(memory[quotient]);
            i++;
        }
        for(i = 0; i <= quotienttemp; i++)
            printf("%llu\n", memory[i]);
        if(remaindertemp == 7) printf("0\n");
    }

    if(type == 1){
        unsigned long long int temp = (unsigned long long) 0;
        int time;
        scanf("%d", &time);

        int i;
        for(i = 0; i < time; i++){
            //printf("hi\n");
            scanf("%llu", &memory[i]);
            //printf("hi\n");
        }
        //printf("hi\n");
        int cnt = 0;
        for(i = 0; i < time; i++){
            int j = 0;
            //printf("hi\n");
            for(j = 0; j < 8; j++){
                temp = memory[i] >> (64 - 8 - j*8);
                //printf("pret = ");
                //printbinary(temp);
                makeallone(8);
                temp = temp & allone;
                //printf("aftt = ");
                //printbinary(temp);
                string[cnt] = temp;
                cnt++;
            }
            string[cnt] = '\0';
        }
        printf("%s", string);
    }
    return 0;
}
