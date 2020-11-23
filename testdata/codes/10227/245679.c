#include<stdio.h>
#include<string.h>

int main(){
	int type;
	scanf("%d", &type);
	char s[100001] = {};
	if(!type){
		scanf("%s", s);
		int len = strlen(s);
		long long result = 0;
		for(int i = 0; i <= len; i++){
			result |= ((long long) s[i] << (56 - 8*(i%8)));
			if(i%8 == 7){
				printf("%lld\n", result);
				result = 0;
			}
			if(i == len && !(i%8 == 7)){
				printf("%lld\n", result);
			}
		}
	}else{
		int n;
		scanf("%d", &n);
		long long to_read;
		int is_done = 0;
		for(int i = 0; i < n && !is_done; i++){
			scanf("%lld", &to_read);
			for(int k = 0; k < 8 && !is_done; k++){
				s[i*8 + k] = to_read >> (56-8*k);
				if(!s[i*8 + k]){
					is_done = 1;
				}
			}
		}
		printf("%s\n", s);
	}
	return 0;
}

