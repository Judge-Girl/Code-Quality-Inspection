#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000
int main () {
	
	char str[MAX_SIZE];
	int x,y;

	while(scanf("%s%d%d", str, &x, &y) != EOF) {

		int vowel[MAX_SIZE] = {};
		char new[3][MAX_SIZE] = {};

		int len = strlen(str);
		//printf("lemn %d\n", len);
		int count = 0;
		for(int i = 0; i < len; i++) {
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				vowel[count] = i;
				//printf("vowel[%d] =  %d %c\n", count, vowel[count], str[i]);
				count++; 
			}
		}
		
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < len ; j++) {
				new[i][j] = '+';
			}
		}

		for(int i = 0; i < len; i++)
			new[2][i] = str[i];

		if(x == 0) {
			int a = 0; 
			while(a <= vowel[x]) {
				new[0][a] = str[a];
				new[2][a] = '+';
				a++;
			}
		} else if(x!= 0) {
			for(int j = vowel[x-1]+1; j <= vowel[x]; j++) {
				new[0][j] = str[j];
				new[2][j] = '+';
			}
		}
		if(y == 0) {
			int a = 0; 
			while(a <= vowel[y]) {
				new[1][a] = str[a];
				new[2][a] = '+';
				a++;
			}
		} else if(y != 0) {
			//printf("vowel[3] = %d, vowel[4] =%d\n", vowel[y-1], vowel[y]);
			for(int j = vowel[y-1]+1; j <= vowel[y]; j++) {

				new[1][j] = str[j];
				new[2][j] = '+';
			}
		}

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < len; j++) {
				printf("%c", new[i][j]);
			}
			printf("\n");
		}
	}
}
