#include <stdio.h>
#include <string.h>

int main(){
	int label;
	scanf("%d", &label);

	if (label == 0){
		char str[100004] = {'\0'};
		scanf("%s", str);

		int len = strlen(str);
		for (int i = 0; i <= len / 8; i ++){
			long long tmp = 0;
			for (int j = 0; j < 8; j ++){
				// printf("%d\n", i * 8 + j);
				// printf("%d\n", str[i * 8 + j]);
				if (i * 8 + j <= len) tmp = (tmp << 8) + (int)str[i * 8 + j];
				else tmp = (tmp << 8);
			}
			printf("%lld\n", tmp);
		}
	}
	if (label == 1){
		int n;
		scanf("%d", &n);

		long long tmp;
		for (int i = 0; i < n; i ++){
			scanf("%lld", &tmp);

			for (int j = 0; j < 8; j ++){
				int res = tmp << (8 * j) >> 56;
				if (res == 0){printf("\0"); break;}
				printf("%c", res);
			}
		}
	}
	return 0;
}

// 0111 0000 0111 0010 0110 1111 0110 0111
// 0111 0010 0110 0001 0110 1101 0111 0011
