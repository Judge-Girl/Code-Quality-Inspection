#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[10010];
char inputf[10050];
int indx[10010];

int main()
{
    long i,j;
    int chi,sli;
    int scnd;
    char *ptr;
    char *blk=" ";
    while(fgets(inputf,10010,stdin)){

        ptr=strtok(inputf,blk);
        strcpy(input,ptr);
        ptr=strtok(NULL,blk);
        i=strtol(ptr,NULL,10);
        ptr=strtok(NULL,blk);
        j=strtol(ptr,NULL,10);

        chi=0;
        sli=1;
        indx[0]=0;

        while(input[chi]!='\0'){
            if(input[chi]=='a'||input[chi]=='e'||input[chi]=='i'||input[chi]=='o'||input[chi]=='u'){
                indx[sli]=chi+1;
                sli++;
            }
            chi++;
        }


        for(chi=0;chi<indx[i];chi++){
            printf("%c",'+');
        }
        for(chi=indx[i];chi<indx[i+1];chi++){
            printf("%c",input[chi]);
        }
        while(input[chi]!='\0'){
            printf("%c",'+');
            chi++;
        }
        printf("\n");

        for(chi=0;chi<indx[j];chi++){
            printf("%c",'+');
        }
        for(chi=indx[j];chi<indx[j+1];chi++){
            printf("%c",input[chi]);
        }
        while(input[chi]!='\0'){
            printf("%c",'+');
            chi++;
        }
        printf("\n");

        chi=0;
        while(input[chi]!='\0'){
            if((chi>=indx[i]&&chi<indx[i+1])||(chi>=indx[j]&&chi<indx[j+1])){
                printf("%c",'+');
            }else{
                printf("%c",input[chi]);
            }
            chi++;
        }
        printf("\n");
    }
}

