#include<stdio.h>
#include<string.h>

int main(){
    char tHeWord[10000]={'\0'},vOwels[5]={'a','e','i','o','u'};
    while(scanf("%s",&tHeWord)!=EOF){
        int a,b,lEngth=strlen(tHeWord),sYll[10001]={0},syll=1;
        sYll[0]=-1;
        scanf("%d%d",&a,&b);
        for(int i=0;i<lEngth;i++){
            for(int ii=0;ii<5;ii++){
                if(tHeWord[i]==vOwels[ii]){
                    sYll[syll]=i;
                    syll++;
                }
            }
        }

        for(int i=0;i<lEngth;i++){
            printf("%c",(i>sYll[a]&&i<=sYll[a+1])?tHeWord[i]:'+');
        }
        printf("\n");
        for(int i=0;i<lEngth;i++){
            printf("%c",(i>sYll[b]&&i<=sYll[b+1])?tHeWord[i]:'+');
        }
        printf("\n");
        for(int i=0;i<lEngth;i++){
            printf("%c",((i>sYll[a]&&i<=sYll[a+1])||(i>sYll[b]&&i<=sYll[b+1]))?'+':tHeWord[i]);
        }
        printf("\n");
    }
    return 0;
}

