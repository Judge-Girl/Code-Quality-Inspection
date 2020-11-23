#include<stdio.h>
#include<string.h>
#define MaxStr 100000
char str[MaxStr];
int main(void)
{
	int type;
	scanf("%d",&type);
	if(!type){
		int bits8 = 0;
		long long ans = 0;
		scanf("%s",str);
		for(int i = 0 ; i < strlen(str) ; i++){
			ans = (ans << 8) | (long long)(str[i]);
			bits8++;
			if(bits8 == 8){
				printf("%lld\n",ans);
				ans = bits8 = 0; 
			}
		}
		ans = ans << (8 * (8 - bits8));
		printf("%lld\n",ans);
	}
	else if(type){
		int num;
		long long input;
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++){
			scanf("%lld",&input);
			for(int j = 7 ; j >= 0 ; j--){
				if((unsigned long long)input >> (56)){
					printf("%c",(unsigned long long)input >> (56));
					input = input << 8; 
				}
				else
					break;
			}
		}
	}
	return 0;
}
