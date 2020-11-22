#include <stdio.h>
#include <string.h>
int main(){
	char input[1000000];
	int T, N, len;
	long long int result, a;
	long long int number[13000], b;
	b = 1;
	scanf("%d", &T);
	if(T == 0){
		scanf("%s", input);
		len = strlen(input) + 1;
		for(int i = 0; i < len; i += 8){
			result = 0;
			for(int j = 0; j < 8; j++){
				a = 0;
				a = a | input[i + j];
				a <<= (7 - j) * 8;
				result = result | a;
			}
			printf("%lld\n", result);
		}
	}
	if(T == 1){
		scanf("%d", &N);
		char output[N * 8];
		int k = 0;
		for(int i = 0; i < N; i++){
			scanf("%lld", &number[i]);
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 8 && b != 0; j++){
				b = number[i];
				b = b >> (7 - j) * 8;
				b &= (long long)255;
				output[k] = b;
				k++;
			}
			if(b == 0){
				break;
			}
		}
		printf("%s\n", output);
	}
	return 0;
} 
