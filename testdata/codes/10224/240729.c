#include <stdio.h>
#include <string.h>
 
int compare(char *a, char *b){ //a為source b為examination
    for(int i=0; i<strlen(a); i++){
        if(a[i]==b[0]){
            int index = 0, ti = i;
            while(a[ti]==b[index] && index<strlen(b) && ti < strlen(a)){
                ti++; index++;
                if(b[index]=='\0'){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int p,isvalid = 1,command;
    int i = 0;
    int amount;
    char temp[512];
    char input[5][32];
    char user[32][80];
    int bank[32] = { 0 };
    scanf("%d",&p);
    for(int i=0; i<p; i++){
        scanf("%s%d",user[i],&bank[i]);
    }
    while(gets(temp)!=NULL){
        int t1=-1,t2=-1;
        isvalid = 1;
        sscanf(temp,"%s%s",input[0],input[1]);
        if(compare(input[1],"earns")){
            command = 1;
        }
        else if(compare(input[1],"spends")){
            command = 2;
        }
        else if(compare(input[1],"gives")){
            command = 3;
        }
        else if(compare(input[1],"becomes")){
            command = 4;
        }
        else continue;
        if(command==3) sscanf(temp,"%s%s%s%d",input[0],input[1],input[2],&amount);
        else sscanf(temp,"%s%s%d",input[0],input[1],&amount);
        for(int i=0; i<p; i++){
            if(!strcmp(input[0],user[i])){
                t1 = i;
                break;
            }
        }
        if(!isvalid || t1==-1) continue;
        if(command==1){
            bank[t1] += amount;
        }
        else if(command==2){
            if(bank[t1]<amount) isvalid = 0;
            else{
                bank[t1] -= amount;
            }
        }
        else if(command==3){
            for(int i=0; i<p; i++){
                if(!strcmp(input[2],user[i])){
                    t2 = i;
                    break;
                }
            }
            if(t2==-1) continue;
            if(bank[t1]<amount) isvalid = 0;
            else{
                bank[t1] -= amount;
                bank[t2] += amount;
            }
        }
        else if(command==4){
            bank[t1] = amount;
        }
        i = 0;
    }
    for(int i=0; i<p; i++){
        printf("%s %d\n",user[i],bank[i]);
    }
    return 0;
}
