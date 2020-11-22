#include <stdio.h>
#include <string.h>

int main(){
  char inp[10005]; int _i,_j;
  char tmp[5]="aiueo";//{'a','b','c','d','e'}
  while(scanf("%s %d %d",inp,&_i,&_j)!=EOF){
    int len=strlen(inp);
    int mem[len+5],idx=0;
  //  printf("%s\n",inp);
    for (int i=0;i<len;i++){
      for (int j=0;j<5;j++){
      //  printf("%c\n",tmp[j]);
        if (inp[i]==tmp[j]){
          mem[idx++]=i;
          j=5;
        }
      }
    }
  //  printf("%d\n",mem[idx-1]);ae
  if (_i==idx-1){
    for (int i=0;i<=mem[_i-1];i++) printf("+");
    for (int i=mem[_i-1]+1;i<=mem[_i];i++) printf("%c",inp[i]);
    for (int i=mem[_i]+1;i<len;i++) printf("+");
    puts("");
  }
  else if (_i==0){
      for (int i=0;i<=mem[_i];i++) printf("%c",inp[i]);
      for (int i=mem[_i]+1;i<len;i++) printf("+");
      puts("");
  }
  else{
    for (int i=0;i<=mem[_i-1];i++) printf("+");
    for (int i=mem[_i-1]+1;i<=mem[_i];i++) printf("%c",inp[i]);
    for (int i=mem[_i]+1;i<len;i++) printf("+");
    puts("");
  }
  if (_j==idx-1){
      for (int i=0;i<=mem[_j-1];i++) printf("+");
      for (int i=mem[_j-1]+1;i<=mem[_j];i++) printf("%c",inp[i]);
      for (int i=mem[_j]+1;i<len;i++) printf("+");
      puts("");
    }
    else if (_j==0){
      for (int i=0;i<=mem[_j];i++) printf("%c",inp[i]);
      for (int i=mem[_j]+1;i<len;i++) printf("+");
      puts("");
    }
    else{
      for (int i=0;i<=mem[_j-1];i++) printf("+");
      for (int i=mem[_j-1]+1;i<=mem[_j];i++) printf("%c",inp[i]);
      for (int i=mem[_j]+1;i<len;i++) printf("+");
      puts("");
    }

    if (_i==idx-1){
      for (int i=mem[_i-1]+1;i<=mem[_i];i++) inp[i]='+';
    }
    else if (_i==0){
        for (int i=0;i<=mem[_i];i++) inp[i]='+';
    }
    else{
      for (int i=mem[_i-1]+1;i<=mem[_i];i++) inp[i]='+';
    }
    if (_j==idx-1){
      for (int i=mem[_j-1]+1;i<=mem[_j];i++) inp[i]='+';
    }
    else if (_j==0){
        for (int i=0;i<=mem[_j];i++) inp[i]='+';
    }
    else{
      for (int i=mem[_j-1]+1;i<=mem[_j];i++) inp[i]='+';
    }
      printf("%s\n",inp);

  }

  #ifdef DDEBUG
    for (int i=0;i<idx;i++) printf("%d\n",mem[i]);
  #endif
  return 0;
}

