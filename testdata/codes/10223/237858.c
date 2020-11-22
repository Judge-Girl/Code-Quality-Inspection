#include <stdio.h>
#include <string.h>
char voc[10005], trash, syllables[10005], vowel[]= "aeiou";
int point[10005], pointstart[10005] = {};
int main(void){
    while(scanf("%s", voc) != EOF){
        int total = 0, len, syl1, syl2, end = 0, flag[10005] = {}, cnt = 0, Cnt = 1, length = strlen(voc);
        char *ptr = voc;
        while(*ptr != '\0'){
            len = strcspn(ptr, vowel);
            total += len + 1;
            point[cnt] = total - 1;
            pointstart[Cnt] = total;
            cnt++;
            Cnt++;
            ptr += len + 1;
        }
        scanf("%d", &syl1);
        for(int i = 0; i < length; i++){
            if(syl1 == 0){
                if(i > point[syl1]) printf("+");
                else{
                    printf("%c", voc[i]);
                    flag[i] = 1;
                }
            }
            else{
                if(i <= point[syl1 - 1]) printf("+");
                else if(i > point[syl1]) printf("+");
                else{
                    printf("%c", voc[i]);
                    flag[i] = 1;
                }
            }
        }
        printf("\n");
        scanf("%d", &syl2);
        for(int i = 0; i < length; i++){
            if(syl2 == 0){
                if(i > point[syl2]) printf("+");
                else{
                    printf("%c", voc[i]);
                    flag[i] = 1;
                }
            }
            else{
                if(i <= point[syl2 - 1]) printf("+");
                else if(i > point[syl2]) printf("+");
                else{
                    printf("%c", voc[i]);
                    flag[i] = 1;
                }
            }
        }
        printf("\n");
        for(int i = 0; i < length; i++){
            if(flag[i] == 0) printf("%c", voc[i]);
            else printf("+");
        }
        printf("\n");
    }
    return 0;
}
