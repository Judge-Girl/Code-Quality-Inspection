#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int i;
	int indice_one, indice_two;
	char word[10000];
	char temp[10000], temp_two[10000];
	while(scanf("%s%d%d", word, &indice_one, &indice_two) != EOF){
		int in_syllable[10000] = {0};
		int now = -1;
		for(i=0; i<strlen(word); i++){
			temp[i] = '+';
			temp_two[i] = '+';
			if(now==indice_one-1){
				if(word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u'){
					temp[i] = word[i];
					word[i] = '+';
					in_syllable[i] = 1;
				}
				else if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
					temp[i] = word[i];
					in_syllable[i] = 1;
					word[i] = '+';
					now ++;
				}
			}
			else if(now==indice_two-1){
				if(word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u'){
					temp_two[i] = word[i];
					word[i] = '+';
					in_syllable[i] = 1;
				}
				else if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
					temp_two[i] = word[i];
					in_syllable[i] = 1;
					word[i] = '+';
					now ++;
				}
			}
			else if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
				now ++;
		}
		temp[strlen(word)] = '\0';
		temp_two[strlen(word)] = '\0';
		printf("%s\n", temp);
		printf("%s\n", temp_two);
		printf("%s\n", word);
	}
	return 0;
}
