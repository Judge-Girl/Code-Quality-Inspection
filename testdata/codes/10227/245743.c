#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
int main(){
	int T;
	scanf("%d", &T);
	if(T == 0){
		char str[100005];
		scanf("%s", str);
		int len = strlen(str);
		str[len] = '\0';
		len += 1;
		int shift = 7;
		ull ULLI = 0;
		for(int i = 0; i < len; i++){
			if(shift) ULLI |= (ull)str[i] << shift*8;
			else if(shift == 0){
				ULLI |= (ull)str[i];
				printf("%llu\n", ULLI);
				ULLI = 0;
				shift = 7;
				continue;
			}
			if(i == len - 1) printf("%llu\n", ULLI);
			shift--;

		}
	}
	else{
		int N;
		scanf("%d", &N);
		ull mask = 0x00000000000000ff;
		ull ULLI;
		ull c;
		//int shift = 7;
		for(int i = 0; i < N; i++){
			scanf("%llu", &ULLI);
			for(int shift = 7; shift >=0; shift--){
				if(shift) c = (ULLI&(mask << shift*8)) >> shift*8;
				else if(shift == 0){
					c = ULLI & mask;
				}
				if(c == '\0') break;
				putchar((char)c);
			}
		}
		puts("");
	}
	return 0;
}
