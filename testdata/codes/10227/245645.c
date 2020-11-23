#include <stdio.h>
#include <string.h>
char s[100000];
unsigned long long output[12500] = {0}, temp;

int main(){
	int type;
	scanf("%d", &type);
	if (!type){
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; i++){
			temp = s[i];
			output[i/8] |= (temp << (7-i%8)*8);
		}
		for (int i = 0; i < len/8 + 1; i++)
			printf("%llu\n", output[i]);
	}
	else if (type){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%llu", &output[i]);
		int i = 0;
		while (1){
			for (int j = 7; j >= 0; j--){
				temp = output[i];
				temp <<= (7-j)*8;
				temp >>= 56;
				// printf("%llu\n", temp);
				if (temp == 0)
					return 0;
				printf("%c", temp);
			}
			i++;
		}
	}
}
