#include<stdio.h>
#include<string.h>

int main(){
	char word[10001] = {};
	int syllable_tail[10001] = {};
	int syllable_head[10001] = {};
	int first, second;
	while(scanf("%s%d%d", word, &first, &second) != EOF){
		int i = 0, count = 0;
		while(word[i]){
			if(word[i] == 'a' ||
			   word[i] == 'e' ||
			   word[i] == 'i' ||
			   word[i] == 'o' ||
			   word[i] == 'u'    ){
				syllable_tail[count] = i;
				count++;
			}
			i++;
		}
		int len = strlen(word);
		int printed[10001] = {};
		int first_head = (first) ? syllable_tail[first-1] : -1;
		for(int i = 0; i < len; i++){
			if(i > first_head && i <= syllable_tail[first]){
				printf("%c", word[i]);
				printed[i]++;
			}else{
				printf("+");
			}
		}
		printf("\n");
		int second_head = (second) ? syllable_tail[second-1] : -1;
		for(int i = 0; i < len; i++){
			if(i > second_head && i <= syllable_tail[second]){
				printf("%c", word[i]);
				printed[i]++;
			}else{
				printf("+");
			}
		}
		printf("\n");
		for(int i = 0; i < len; i++){
			if(!printed[i]){
				printf("%c", word[i]);
			}else{
				printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}

