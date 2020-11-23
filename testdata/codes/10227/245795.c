#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d\n", &T);
	if (T == 0){  // str_to_integer
		
	
		char S[100000] = {0};
		int str_n = 0;
		while(scanf("%c", &S[str_n]) != EOF && S[str_n] != '\n')
			str_n++;
//		for (int i = 0; i < str_n; i++)	
//			printf("%c", S[i]);
		int int_n =  str_n / 8 + 1;
		unsigned long long integer[int_n];
		for (int i = 0; i < int_n;i++)
			integer[i] = 0;
		int n = 0;
//		printf("str_n %d n %d\n",str_n, n);
		for (int i = 0; i < str_n; i++){
			unsigned long long word = S[i];
			int move_left = 8 - (i%8) - 1;
			word = word << (move_left * 8);
			integer[n] = integer[n] | word;
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
			int end = 0;
			for (int i = 7; i >= 0; i--){
				if (integer[n] & test){
					unsigned long long word = integer[n] & test;
					word = word >> (8 * i);
					unsigned char print = word;
					printf("%c", word);
				}
				
				else{
					end = 1;
					break;
				}
				test = test >> 8;
			}
			if (end) break;
		}
		
	}
	
	return 0;
}
