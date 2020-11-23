#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nvowel[]={"bcdefghjklmnpqrstvwxyz"};
    char words[10000];
    int a,b;
    while(scanf("%s",words)!=-1){
        char *word=words;
        scanf("%d%d",&a,&b);
        int n=strlen(words);
        int pos[10000];
        int l=0,k=1;
        pos[0]=-1;
        for(int i=0;i<n;i++){
            if(words[i]=='a' ||words[i]=='e' ||words[i]=='i' ||words[i]=='o' ||words[i]=='u'){
                pos[k]=i;
                k++;
            }
        }
        for(int i=0;i<n;i++){
            if(i>pos[a]&&i<=pos[a+1]){
                printf("%c",words[i]);
            }
            else printf("+");
        }
        printf("\n");
        for(int i=0;i<n;i++){
            if(i>pos[b]&&i<=pos[b+1]){
                printf("%c",words[i]);
            }
            else printf("+");
        }
        printf("\n");
        for(int i=0;i<n;i++){
            if((i>pos[a]&&i<=pos[a+1]) || (i>pos[b]&&i<=pos[b+1]) ) {
                printf("+");
            }
            else printf("%c",words[i]);
        }
        printf("\n");

    }
}

