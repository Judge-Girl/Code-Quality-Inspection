#include<stdio.h>
#include<string.h>
int main(){
    unsigned long long int x[12510];
    char s[100010]={'\0'};
    int T,N;
    scanf("%d",&T);
    if(T==0){
      for(int i=0;i<12510;i++){
        x[i]=0;
      }
      scanf("%s",s);
      int l=strlen(s),bit=64,n=0;
      for(int i=0;i<l;i++){
        bit-=8;
        if(bit){
          x[n]|=(unsigned long long int)s[i]<<bit; 
        }
        else{
          x[n]|=(unsigned long long int)s[i];
          bit=64;
          n++;
        }
      }
      if(bit){
        bit-=8;
        x[n]|=(unsigned long long int)0<<bit;
      }
      else{
        n++;
        x[n]=0;
      }
      for(int i=0;i<=n;i++){
        printf("%lld\n",x[i]);
      }
    }
    else {
        scanf("%d",&N);
        for(int i=0;i<N;i++){
          scanf("%lld",&x[i]);
        }
        int c=0;
        for(int i=0;i<N;i++){
          for(int j=1;j<=8;j++){
            int bit=64-j*8;
            if(bit){
              s[c]=(char)((x[i]>>bit)&((1<<8)-1));
              c++;
            }
            else {
              s[c]=(char)(x[i]&((1<<8)-1));
              c++;
            }
          }
        }
        printf("%s",s);
    }
}
