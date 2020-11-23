#include <stdio.h>
#include <string.h>
#define length 10000
char string[length];
char syl[length][length],syl1[length];
int main(){
  int i,j;
  char vowel[]="aeiou";

  while(scanf("%s %d %d",string,&i,&j)!=EOF){
    int index=0,jm,im,last=0;

    for(int i=0;i<strlen(string);i++){
      int yes=0;
      for(int j=0;j<5;j++){
        if(string[i]==vowel[j]) {yes=1;im=i;break;}
      }

      if(yes){
        for(int i=0;i<last;i++){
          syl[index][i]='+';
        }
        for(int i=last;i<im+1;i++){
          syl[index][i]=string[i];
        }
        for(int i=im+1;i<strlen(string);i++){
          syl[index][i]='+';
        }
        syl[index][strlen(string)]='\0';
        last=im+1;
        index++;
      }
    }
    for(int k=0;k<strlen(string);k++){
      if(syl[i][k]=='+' && syl[j][k]=='+'){
        syl1[k]=string[k];
      }
      else syl1[k]='+';
    }
    syl1[strlen(string)]='\0';

    printf("%s\n%s\n%s\n",syl[i],syl[j],syl1);
  }
  return 0;
}

