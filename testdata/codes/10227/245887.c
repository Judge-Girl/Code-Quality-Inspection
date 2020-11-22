#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 12800
#define MAXS 1024000

int main() {
	int T;
	char S[MAXS];

	scanf("%d", &T);

	if(T == 0) {
		long long int ret = 0;
		scanf("%s", S);
		int flag = 0;
		int lenS = strlen(S);
		// strcat(S, "\0");
		for(int i = 0; i < lenS; i++) {
			ret += (unsigned long long) S[i];

			if(i % 8 == 7){
				printf("%lld\n", ret);
				ret = 0;
				if (i == lenS - 1) {
					printf("0\n");
				} 

				continue;
			}



			ret <<= 8;

			if (i % 8 != 7 && i == lenS - 1){
				ret <<= (8 * (7 - (i % 8) - 1));
				printf("%lld\n", ret);
			}



			// if (i == lenS - 1 && flag == 0) {
			// 	ret <<= (8 * (7 - (i % 8)));
			// 	printf("%lld\n", ret);
			// 	flag = 1;
			// }	

		}

		
	}
	else if (T == 1) {
		int countSeq;
		scanf("%d", &countSeq);
		long long int ret2;
		char ret[MAXS];
		int cnt = 0;
		while(countSeq--) {
			scanf("%llu", &ret2);

			for(int i = 7; i >= 0; i--) {
				ret[cnt++] = (ret2 >> (8 * i)) & 511;
			}
		}
		int l = strlen(ret);
		ret[l] = '\0';

		printf("%s\n", ret);
	}
	return 0;
}
