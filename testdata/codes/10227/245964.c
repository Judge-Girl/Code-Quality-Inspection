#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
  if (n==0){
    char inp[100005];
    while(scanf("%s",inp)!=EOF){
      unsigned long long ans=0;
      int x=0;
      for (int i=0;i<strlen(inp);i++){
        x++;
        ans<<=(unsigned long long)8;
        ans+=inp[i];
        if (x==8){
          x=0;
          printf("%llu\n",ans);
          ans=(unsigned long long)0;
        }
      }
      if (x!=0){
        while(x!=8){
          x++;
          ans<<=(unsigned long long)8;
        }
        printf("%llu\n",ans);
      }
      else{
        puts("0");
      }
    }
  }
  else{
    int tc;
    scanf("%d",&tc);
    unsigned long long pangkat2[70]; pangkat2[0]=1;
    for (int i=1;i<63;i++) pangkat2[i]=pangkat2[i-1]*2;
    //for (int i=1;i<63;i++) printf("%llu\n",pangkat2[i]);
    char outp[100005]; int idx=0;
    unsigned long long b[125005];
    for (int i=0;i<tc;i++)scanf("%llu",&b[i]);
    for (int j=tc-1;j>=0;j--){
      unsigned long long a=b[j];

      int id=0; long long ans=0;
      while(a){
        if (a&1) ans+=pangkat2[id];
        a>>=1;
        id++;
        if (id==8){
          id=0;
          if (ans!=0) outp[idx++]='A'+((int)ans-'A');
          ans=0;
        }
      }
      if (id!=0){if (ans!=0) outp[idx++]='A'+((int)ans-'A');}
    }
    for (int i=idx-1;i>=0;i--) if(outp[i]!='\0') printf("%c",outp[i]);
    printf("\n");
  }
  return 0;
}

