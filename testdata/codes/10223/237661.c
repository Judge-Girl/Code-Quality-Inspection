#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,con1,con2,con3,answer=0,lng,x,y;
    char vowel[5];
    vowel[0]='a',vowel[1]='e',vowel[2]='i',vowel[3]='o',vowel[4]='u';
    char string[10001];
    char *ptr=string;
    char ans1[10001],ans2[10001],ans3[10001],ans0[10001];
    while(scanf("%s",string)!=EOF){
        for(con1=0;con1<10001;con1++){
            ans3[con1]='+';
            ans1[con1]='+';
            ans2[con1]='+';
        }
        answer=0;
        scanf("%d%d",&i,&j);
        con2=0;
        lng=strlen(ptr);
        for(con1=0;con1<lng;con1++){
            for(x=0;x<5;x++){
                if(ptr[con1]==vowel[x]){
                    if(answer==i){
                        for(con3=con2;con3<=con1;con3++){
                            ans1[con3]=ptr[con3];
                        }
                    }
                    else if(answer==j){
                        for(con3=con2;con3<=con1;con3++){
                            ans2[con3]=ptr[con3];
                        }
                    }
                    else{
                        for(con3=con2;con3<=con1;con3++){
                            ans3[con3]=ptr[con3];
                        }
                    }
                    con2=con1+1;
                    answer++;
                    break;
                }
            }
        }
        if(con2<lng){
            for(con1=con2;con1<lng;con1++){
                ans3[con1]=ptr[con1];
            }
        }
        for(con1=0;con1<lng;con1++){
            printf("%c",ans1[con1]);
        }
        printf("\n");
        for(con1=0;con1<lng;con1++){
            printf("%c",ans2[con1]);
        }
        printf("\n");
        for(con1=0;con1<lng;con1++){
            printf("%c",ans3[con1]);
        }
        printf("\n");
    }
}
