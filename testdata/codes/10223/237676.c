#include <stdio.h>
#include <string.h>
char input[10000] ;
char first[10000] ;
char second[10000] ;
char last[10000] ;
int line[10000];
int main(){
    int a , b;
    while(scanf("%s%d%d" , input , &a , &b )!=EOF){
        int I = 0;
        for(; I < strlen(input) ; I++){
            first[I] = '+';
            second[I] = '+';
        }
        first[I] = '\0' ;
        second[I] = '\0' ;
        strcpy(last , input);
        int j = 0;
        for(int i = 0 ; i < strlen(input); i++){
            if( input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ){
                line[j] = i;
                j++;
            }
        }

        if(a == 0){
            for(int k = line[a] ; k > -1 ; k-- ){
                first[k] = input[k];
                last[k] = '+' ;
            }
        }
        else{
            for(int k = line[a] ; k > line[a-1] ; k-- ){
                first[k] = input[k];
                last[k] = '+' ;
            }
        }
        if(b == 0){
            for(int k = line[b] ; k > -1 ; k-- ){
                second[k] = input[k];
                last[k] = '+' ;
            }
        }
        else{
            for(int k = line[b] ; k > line[b-1] ; k-- ){
                second[k] = input[k];
                last[k] = '+' ;
            }
        }
        printf("%s\n" , first);
        printf("%s\n" , second);
        printf("%s\n" , last);
    }
    return 0;
}

