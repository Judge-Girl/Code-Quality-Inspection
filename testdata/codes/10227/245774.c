#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	if(t==0){
		char string[100001];
		scanf("%s",&string);
		int num=strlen(string),constnum=strlen(string);
		long long int N=0;
		while(num>=8){
			N=0;
			for(int i=0;i<8;i++){
				N=((long long int)string[constnum-num+i])+(N<<8); 
			}
			printf("%lld\n",N);
			num-=8;
		}
		N=0;
		for(int i=0;i<num;i++){
			N=((long long int)string[constnum-num+i])+(N<<8); 
		}
		N=N<<(64-8*num);
		printf("%lld",N);
	}
	else{
		int i;
		long long int n;
		scanf("%d",&i);
		while(i--){
			scanf("%lld",&n);
			for(int j=0;j<8;j++){
				char temp=(char)((n>>(56-8*j)&(~0)));
				if(temp=='\0')break;
				else printf("%c",temp);
			}
		}
		printf("\0");
	}
	return 0;
} 
