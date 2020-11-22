#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long
char str[100050];

int main(){
int sw;
memset(str,0,sizeof(str));
scanf("%d",&sw);
if(sw){
int n;
scanf("%d",&n);
ll in;
for(int i = 0;i<n;i++){
scanf("%lld",&in);
#ifdef DEBUG
printf("in : %lld\n",in);
#endif
for(int j = 0;j<8;j++)str[i*8+j] = (char) (in>>(8*(7-j)));
}
printf("%s\n",str);
}else{
scanf("%s",str);
int le = strlen(str);
le++;
for(int i = 0;i*8<le;i++){
ll o = 0;
for(int j = 0;j<8;j++)o|=(str[8*i+j]*1ll)<<(8*(7-j));
printf("%lld\n",o);
}

}

}

