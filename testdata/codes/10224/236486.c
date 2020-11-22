#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
  int n;
  scanf("%d",&n);
  char user[n][32];
  int balance[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%s %d",user[i],&balance[i]);
  }
  char instruction[130];
  while(fgets(instruction,130,stdin)!=NULL){
    char a[32],ins[32],b[32],cha[32],end;
    int chan;
    sscanf(instruction,"%s %s %s%c",a,ins,cha,&end);
    if(end=='\n'){
      int ai=-1;
      for(i=0;i<n;i++){
        if(strcmp(a,user[i])==0){
          ai=i;
          break;
        }
      }
      if(ai>=0){
        chan = atoi(cha);
        char *ptr;
        ptr = strstr(ins,"earns");
        if(ptr != NULL){
          balance[ai] = balance[ai]+chan;
          continue;
        }
        ptr = strstr(ins,"spends");
        if(ptr != NULL && balance[ai]>=chan){
          balance[ai] = balance[ai]-chan;
          continue;
        }
        ptr = strstr(ins,"becomes");
        if(ptr != NULL){
          balance[ai] = chan;
          continue;
        }
      }
    }
    else{
      sscanf(instruction,"%s %s %s %s%c",a,ins,b,cha,&end);
      if(end=='\n'){
        int ai=-1,bi=-1;
          for(i=0;i<n;i++){
          if(strcmp(a,user[i])==0){
            ai=i;
            break;
          }
        }
        for(i=0;i<n;i++){
          if(strcmp(b,user[i])==0){
            bi=i;
            break;
          }
        }
        if(ai>-1 && bi>-1){
          chan = atoi(cha);
          char *ptr;
          ptr = strstr(ins,"gives");
          if(ptr != NULL && balance[ai]>=chan){
            balance[ai] = balance[ai]-chan;
            balance[bi] = balance[bi]+chan;
          }
        }
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%s %d\n",user[i],balance[i]);
  }
  return 0;
}
