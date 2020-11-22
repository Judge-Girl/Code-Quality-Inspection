#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char vowel[16] = {'a', 'e', 'i', 'o', 'u'};
int syllablePos[10000+5] = {0};

int main() {
	char S[10000+5];
	int m, n;


	while(scanf("%s %d %d", S, &m, &n) != EOF) {
		int len = strlen(S);
		int numOfSyllable = 0;

		char cross1[10000+5] = "";
		char cross2[10000+5] = "";
		char cross3[10000+5] = "";
		for (int i = 0; i < len; i++) {
			cross1[i] = '+';
			cross2[i] = '+';
			cross3[i] = '+';
		}
		cross1[len] = '\0';
		cross2[len] = '\0';
		cross3[len] = '\0';

		// printf("cross: %s\n", cross);


		for (int i = 0; i < len; i++) {
			if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
				syllablePos[numOfSyllable++] = i;
			}
		}

		
		int complete = 0;
		if(syllablePos[numOfSyllable - 1] == len) complete = 1;


		if (m > 0) {
			for(int i = syllablePos[m - 1] + 1; i <= syllablePos[m]; i++) {
				cross1[i] = S[i];
			}
		} else if (m == 0) {
			for (int i = 0; i <= syllablePos[0]; i++) {
				cross1[i] = S[i];
			}
		}

		if (n > 0) {
			for(int i = syllablePos[n - 1] + 1; i <= syllablePos[n]; i++) {
				cross2[i] = S[i];
			}
		} else if (n == 0) {
			for (int i = 0; i <= syllablePos[0]; i++) {
				cross2[i] = S[i];
			}
		}


		for(int i = 0; i < len; i++) {
			if(cross1[i] == '+' && cross2[i] == '+') 
				cross3[i] = S[i];
		}


		puts(cross1);
		puts(cross2);
		puts(cross3);

		

	}


	return 0;
}
