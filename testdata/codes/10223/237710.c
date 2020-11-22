#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char word[10000];
    while(scanf("%s",word)!=EOF){
        int index[10000]={0};
        int i = 0, j = 0;
        int len = strlen(word);
        //printf("len = %d\n",len);

        while(word[i] != EOF){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
                index[j] = i;
                j++;
            }
            i++;
        }
        int first, second;
        scanf("%d%d", &first, &second);
        char ans1[len];
        int check[10000] = {0};
        int cnt;
        if(first == 0){
            for(cnt = 0; cnt <= index[first]; cnt++){
                ans1[cnt] = word[cnt];
                check[cnt]++;
            }
            for(cnt = index[first]+1; cnt < len; cnt++){
                ans1[cnt] = '+';
            }
        }
        else{
            for(cnt = 0; cnt < index[first]; cnt++){
                ans1[cnt] = '+';
            }
            for(cnt = index[first-1]+1; cnt <= index[first]; cnt++){
                ans1[cnt] = word[cnt];
                check[cnt]++;
            }
            for(cnt = index[first]+1; cnt < len; cnt++){
                ans1[cnt] = '+';
            }
        }

        char ans2[len];
        if(second == 0){
            for(cnt = 0; cnt <= index[second]; cnt++){
                ans2[cnt] = word[cnt];
                check[cnt]++;
            }
            for(cnt = index[second]+1; cnt < len; cnt++){
                ans2[cnt] = '+';
            }
        }
        else{
            for(cnt = 0; cnt < index[second]; cnt++){
                ans2[cnt] = '+';
            }
            for(cnt = index[second-1]+1; cnt <= index[second]; cnt++){
                ans2[cnt] = word[cnt];
                check[cnt]++;
            }
            for(cnt = index[second]+1; cnt < len; cnt++){
                ans2[cnt] = '+';
            }
        }

        char ans3[len];
        for(cnt = 0; cnt < len; cnt++){
            if(check[cnt] == 0)
                ans3[cnt] = word[cnt];
            else ans3[cnt] = '+';
        }

        for(cnt = 0; cnt < len; cnt++){
             printf((cnt == len-1)?"%c\n":"%c", ans1[cnt]);
        }
        for(cnt = 0; cnt < len; cnt++){
            printf((cnt == len-1)?"%c\n":"%c", ans2[cnt]);
        }
        for(cnt = 0; cnt < len; cnt++){
            printf((cnt == len-1)?"%c\n":"%c", ans3[cnt]);
        }
        //printf("%s\n", ans1);
        //printf("%s\n", ans2);
        //printf("%s\n", ans3);
    }
}

