#include <stdio.h>
#include <string.h>
char S[100000];
long long int store[12500];
long long int store2[12500];
char p[12500][8];
char s[12500][8];
main(){
int T,N,i,k,m;
long long int j;
scanf("%d",&T);

switch(T){
case 0:{
scanf("%s",S);
int l=strlen(S);
int mod1,mod2;
for(i=0;i<l;i++){
    mod1=i/8;
    mod2=i%8;
    s[mod1][mod2]=S[i];
}
for(i=0;i<=l/8;i++){
    for(k=0;k<8;k++){
            j=s[i][k];
            store[i] = (store[i] << 8) | j;
    }
}
for(i=0;i<=l/8;i++){
    printf("%lld\n",store[i]);
}
break;
}
case 1:{
scanf("%d",&N);
for(i=0;i<N;i++){
    scanf("%lld",&store2[i]);
}
long long int b=0,q=0,r=0;
for(k=0;k<N;k++){
for(i=7;i>=0;i--){
q=b;
b = store2[k] >> (i*8);
r = b & ~(q << 8);
s[k][7-i]=r;
}
}
for(k=0;k<N;k++){
for(i=0;i<8;i++){
    if(s[k][i]!=0)
    printf("%c",s[k][i]);
}
}





break;
}
default:
break;
}





}

