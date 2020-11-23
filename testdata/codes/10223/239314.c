#include <stdio.h>
#include <string.h>

int main(){
        char str[10020];
        char plus1[10020];
        char plus2[10020];
        for(int i = 0; i < 10020; i++){
                plus1[i] = '+';
                plus2[i] = '+';
        }
        int i1, i2;
        char vowel[5] = "aeiou";
        while(scanf("%s %d %d", str, &i1, &i2) != EOF){
                plus1[strlen(str)] = 0;
                int syl[10020] = {0};
                int cnt = 1;
                for(int i = 0; i < strlen(str); i++){
                        for(int j = 0; j < 5; j++){
                                if(str[i] == vowel[j]){
                                        syl[cnt++] = i+1;
                                        break;
                                }
                        }
                }
                strncpy(plus1+syl[i1], str+syl[i1], syl[i1+1]-syl[i1]);
                printf("%s\n", plus1);
                strncpy(str+syl[i1], plus2+syl[i1], syl[i1+1]-syl[i1]);
                strncpy(plus1+syl[i1], plus2+syl[i1], syl[i1+1]-syl[i1]);

                strncpy(plus1+syl[i2], str+syl[i2], syl[i2+1]-syl[i2]);
                printf("%s\n", plus1);
                strncpy(str+syl[i2], plus2+syl[i2], syl[i2+1]-syl[i2]);
                strncpy(plus1, plus2, 10020);
                printf("%s\n", str);
        }

}
