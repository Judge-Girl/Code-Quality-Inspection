#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d\n", &T);
	if (T == 0){
		char S[100000] = {0};
		int str_n = 0;
		while(scanf("%c", &S[str_n]) != EOF && S[str_n] != '\n')
			str_n++;
			
		int int_n =  str_n / 8 + 1;
		unsigned long long integer[int_n];
		for (int i = 0; i < int_n; i++)
			integer[i] = 0;
			
		int n = 0;
		for (int i = 0; i < str_n; i++){
			unsigned long long word = S[i];
			int move_left = 8 - (i % 8) - 1;
			word = word << (move_left * 8);
			integer[n] |= word;
			if (i % 8 == 7){
				n++;
			}
		}
	
		for (int i = 0; i < int_n; i++)
			printf("%llu\n", integer[i]);
	}
	else {
		int N;
		scanf("%d", &N);
		unsigned long long integer[N];
		for (int n = 0; n < N; n++)
			scanf("%llu", &integer[n]);
		
		for (int n = 0; n < N; n++){
			unsigned long long test = 255;
			test = test << 56;
			for (int i = 7; i >= 0; i--){
				if (integer[n] & test){
					unsigned long long word = integer[n] & test;
					word = word >> (8 * i);
					unsigned char print = word;
					printf("%c", word);
					test = test >> 8;
				}
				else{
					return 0;
				}
			}
		}
	}
	
	return 0;
}
