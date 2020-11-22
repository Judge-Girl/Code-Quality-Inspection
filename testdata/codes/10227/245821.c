#include <stdio.h>
#include <string.h>
char s[100000+5];
int main(){
	int T;
	scanf("%d",&T);
	if(T == 0){
		scanf("%s",s);
		int len = strlen(s);
		long long ans = 0;
		//printf("len %d\n",len);
		int flag = 1;
		for(int i = 0; i < len; i++){
			ans <<= 8;
			ans += s[i];
			if(i % 8 == 7){
				printf("%lld\n",ans);
				ans = (long long)0;
			}
		}
		if(len % 8 == 0) printf("0\n");
		else {
			ans <<= 8 * (8 - len % 8);
			printf("%lld\n",ans);
		}
	}
	else{
		int n;
		scanf("%d",&n);
		long long ref = 255;
		while(n--){
			long long num;
			scanf("%lld",&num);
			int flag = 0;
			for(int i = 7; i >= 0; i--){
				if(((num >> i*8) & 255) == 0) {
					break;
				}
				else {
					printf("%c",((num >> i*8) & 255));
				}
			}
		}
	}
	return 0;
}
