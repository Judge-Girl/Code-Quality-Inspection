#include<stdio.h>
#include<string.h>
int main(){
char s[10010], s1[10010], s2[10010];
int fir, sec, i, vowel[10000], j;
while(scanf("%s", s)!=EOF){
    scanf("%d %d", &fir, &sec);
    int len=strlen(s);
    int count=0, used[10010]={0};
    for(i=0; i<len; i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            vowel[count]=i;
            count++;
        }
    }
    for(i=0; i<len; i++){
        if(fir==0){
            for(j=0; j<=vowel[0]; j++){
                s1[j]=s[j];
                used[j]=1;
            }
            for(j=vowel[0]+1; j<len; j++){
                s1[j]='+';
            }
            break;
        }
        if(i>vowel[fir-1]&&i<=vowel[fir]){
            s1[i]=s[i];
            used[i]=1;
        }
        else{
            s1[i]='+';
        }
    }
    for(i=0; i<len; i++){
        if(sec==0){
            for(j=0; j<=vowel[0]; j++){
                s2[j]=s[j];
                used[j]=1;
            }
            for(j=vowel[0]+1; j<len; j++){
                s2[j]='+';
            }
            break;
        }
        if(i>vowel[sec-1]&&i<=vowel[sec]){
            s2[i]=s[i];
            used[i]=1;
        }
        else{
            s2[i]='+';
        }
    }
    for(i=0; i<len; i++){
        if(used[i]!=0){
            s[i]='+';
        }
    }
    s[len]='\0';
    s1[len]='\0';
    s2[len]='\0';
    printf("%s\n%s\n%s\n", s1, s2, s);
}
}

