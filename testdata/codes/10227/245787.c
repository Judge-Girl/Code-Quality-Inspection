#include <stdio.h>
#include <string.h>
#define len 100000
int main(){
  int task,index=63;
  char str[len];
  unsigned long long mask=1,result=0;

  scanf("%d",&task);
  if(!task){
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
      for(int j=7;j>=0;j--){
        if(str[i]&(mask<<j)) result+=(mask<<index);
        index--;
      }
      if((i+1)%8==0){
        printf("%llu\n",result);
        result=0;
        index=63;
      }
    }
    if(str[strlen(str)+1]=='\0') printf("%llu\n",result);
  }

  if(task){
    int total;
    unsigned long long input,index=7,in=0;
    char output[len];

    for(int i=0;i<len;i++) output[i]=0;
    scanf("%d",&total);
    for(int i=0;i<total;i++){
      scanf("%llu",&input);
      for(int j=63;j>=0;j--){
        if(input&(mask<<j)) output[in]+=mask<<index;
        index--;
        if(j%8==0) {in++;index=7;}
      }
    }
    printf("%s\n",output);
  }

}

