#include <stdio.h>
#include <string.h>

int main(){
	char word[10000];
	int a, b;
	while(scanf("%s %d %d", word, &a, &b) != EOF){
		int len = strlen(word), vl = 0, vowel[10000] = {0};
		for (int i = 0; i < len; ++i){
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
				vowel[vl] = i;
				vl++;
			}
		}
		if (a == 0){
			for (int i = 0; i <= vowel[0]; i++){
				printf("%c", word[i]);
				word[i] = '+';
			}
			for (int i = vowel[0]+1; i < len; i++)
				printf("+");
		}
		else{
			for (int i = 0; i < len; i++){
				if (i > vowel[a-1] && i <= vowel[a] && a-1 >= 0){
					printf("%c", word[i]);
					word[i] = '+';
				}
				else printf("+");
			}
		}
		printf("\n");
		if (b == 0){
			for (int i = 0; i <= vowel[0]; i++){
				printf("%c", word[i]);
				word[i] = '+';
			}
			for (int i = vowel[0]+1; i < len; i++)
				printf("+");
		}
		else{
			for (int i = 0; i < len; i++){
				if (i > vowel[b-1] && i <= vowel[b] && b-1 >= 0){
					printf("%c", word[i]);
					word[i] = '+';
				}
				else printf("+");
			}
		}
		printf("\n");
		for (int i = 0; i < len; i++)
			printf("%c", word[i]);
		printf("\n");
	}
}
