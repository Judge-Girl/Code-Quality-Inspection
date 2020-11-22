#include <stdio.h>
#include <string.h>
#define isVow(A) A=='a'||A=='e'||A=='i'||A=='u'||A=='o'
char in[10005];
char l1[10005];
char l2[10005];
char l3[10005];
int main(){
int i,j;
while(scanf("%s%d%d",in,&i,&j)!=EOF){
int sybc = 0;
int len = strlen(in);
for(int o = 0;o<len;o++){
if(sybc==i){
l1[o] = in[o];
l2[o] = '+';
l3[o] = '+';
}else if(sybc==j){
l1[o] = '+';
l2[o] = in[o];
l3[o] = '+';
}else{
l1[o]='+';
l2[o] = '+';
l3[o] = in[o];
}
sybc+=isVow(in[o]);
}
l1[len] = '\0';
l2[len] = '\0';
l3[len] = '\0';
printf("%s\n%s\n%s\n",l1,l2,l3);}
return 0;
}
