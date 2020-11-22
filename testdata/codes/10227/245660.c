#include<stdio.h>
#include<string.h>

int main(){
	int mode;
	scanf("%d", &mode);
	if(mode == 0){
		char string[100000];
		scanf("%s", string);
		int l = strlen(string);
		long long int ans=0;
		for(int i=0; i<l+1; i++){
			ans = (ans << 8) + string[i];
			if(i%8 == 7){
				printf("%lld\n", ans);
			}
		}
		for(int i=l+1; l%8 != 7; i++){
			ans = (ans << 8);
			if(i%8 == 7){
				printf("%lld\n", ans);
				break;
			}
		}
	}
	else if(mode == 1){
		char string[1000000];
		int N, s=0;
		long long int input;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int num = 56;
			scanf("%lld", &input);
			for(int j=0; j<8; j++){
				//printf("%c", (input>>num) & 255);
				string[s] = (input>>num) & 255;
				s++;
				if((input>>num) & 255 == '\0') break;
				num -= 8;
			}
		}
		printf("%s", string);
	}
} 
