#include <stdio.h>
#include <string.h>

#define MAXLEN 10100
#define bool int
#define true 1
#define false 0

const char vowels[] = "aeiou";
bool is_vowels(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int main(){
    char word[MAXLEN];
    int I, J;
    while(scanf("%s%d%d", word, &I, &J) != EOF){
        char output[3][MAXLEN];
        // init
        for(int i=0; i<3; i++)
            for(int j=0; j<MAXLEN; j++)
                output[i][j] = '+';
        // process
        int word_count=0, current_idx=0, current_len=0;
        while(current_idx < strlen(word)){
            char buffer[MAXLEN];
            int buffer_ins=0;
            while(!is_vowels(word[current_idx]) && current_idx<strlen(word)){
                buffer[buffer_ins++] = word[current_idx++];
            }
            buffer[buffer_ins++] = word[current_idx++];
            buffer[buffer_ins++] = '\0';
            //printf("%s\n", buffer);

            if(word_count == I){
                strcpy(&output[0][current_len], buffer);
                current_len += strlen(buffer);
                if(current_len != strlen(word)) output[0][current_len] = '+';
            }
            else if(word_count == J){
                strcpy(&output[1][current_len], buffer);
                current_len += strlen(buffer);
                if(current_len != strlen(word)) output[1][current_len] = '+';
            }
            else{
                strcpy(&output[2][current_len], buffer);
                current_len += strlen(buffer);
                if(current_len != strlen(word)) output[2][current_len] = '+';
            }
            word_count ++;
        }

        for(int i=0; i<3; i++){
            output[i][strlen(word)] = '\0';
            printf("%s\n", output[i]);
        }
    }

    return 0;
}

