#include <stdio.h>
#include <string.h>
int main(){
	char letter[10000];
	char *vowel[10000];
	char *start;
	int first,second;
	while(scanf("%s",letter) != EOF){
		int vowel_index = 0;
		scanf("%d%d",&first,&second);
		start = letter;
		while(*start != '\0'){
			if (*start != 'a' &&
				*start != 'e' &&
				*start != 'i' &&
				*start != 'o' &&
				*start != 'u'){
				start++;
				continue;
			}
			vowel[vowel_index] = start;
			vowel_index++;
			start++;
		}
		start = letter;
		char *head;
		if (first == 0)
			head = letter;
		else
			head = vowel[first - 1] + 1;
		while(*start != '\0'){
			if (start - head >= 0 && vowel[first] - start >= 0)
				printf("%c",*start);
			else
				printf("+");
			start++;
		}
		printf("\n");
		char *head2;
		start = letter;
		if (second == 0)
			head2 = letter;
		else
			head2 = vowel[second - 1] + 1;
		while(*start != '\0'){
			if (start - head2 >= 0 && vowel[second] - start >= 0)
				printf("%c",*start);
			else
				printf("+");
			start++;
		}
		printf("\n");
		start = letter;
		while(*start != '\0'){
			if (start - head2 >= 0 && vowel[second] - start >= 0 ||
				start - head >= 0 && vowel[first] - start >= 0)
				printf("+");
			else
				printf("%c",*start);
			start++;
		}
		printf("\n");
	}

}
