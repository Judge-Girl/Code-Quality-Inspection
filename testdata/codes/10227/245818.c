#include <stdio.h>
#include <string.h>
void to_int(char string[]){
	int i = 0;
	unsigned long long ans = 0;
	while(string[i] != '\0'){
		if(i % 8 == 0 && i != 0){
			printf("%lld\n", ans);
			ans = 0;
		}
		ans <<= 8;
		ans |= string[i++];
		// printf("%d\n", i);
	}
	// printf("%d\n", i);
	ans <<= 8*(8 - (i % 8));
	printf("%lld\n", ans);
	if(i % 8 == 0)
		printf("%d\n", 0);
	return ;
}
void to_string(int n, unsigned long long int num[]){
	unsigned long long int x = (-1LL << 56);
	char ans = (x & num[0]) >> 56;
	int cnt = 0, i = 0;
	while(ans != '\0'){
		printf("%c", ans);
		// printf("%d\n", cnt);
		cnt++;
		if(cnt % 8 == 0){
			i++; cnt = 0;
		}
		if(cnt != 0)
			num[i] <<= 8;
		ans = (x & num[i]) >> 56;
	}
	return;
}


int main(){
	int mode, n;
	scanf("%d", &mode);
	unsigned long long int num[12500];
	char string[100000];
	switch(mode){
		case 0:
			scanf("%s", string);
			to_int(string);
		break;
		case 1:
			scanf("%d", &n);
			for(int i = 0; i < n; i++)
				scanf("%lld", &(num[i]));
			to_string(n, num);
	}
	return 0;
}
