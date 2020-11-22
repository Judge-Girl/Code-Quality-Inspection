#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
	char string[10100], output[10100];
	int i, j;
	int count_i, count_j;
	int count_i_pre, count_j_pre;
	int stop_i, stop_j, stop_i_pre, stop_j_pre;
	while(~scanf("%s", string)){
		char a[strlen(string) + 1];
		for(int k = 0; k < strlen(string); k++){
			a[k] = '+';
		}
		a[strlen(string)] = '\0';
		stop_i = stop_j = stop_i_pre = stop_j_pre = 0;
		int count_vowel = -1;
		scanf("%d%d", &i, &j);
		for(int k = 0; k < strlen(string); k++){
			if(string[k] == 'a' || string[k] == 'e' || string[k] == 'i' || string[k] == 'o' || string[k] == 'u'){
				count_vowel++;
			}
			if(count_vowel == i - 1 && stop_i_pre == 0){
				count_i_pre = k;
				stop_i_pre = 1;
			}
			if(count_vowel == i && stop_i == 0){
				count_i = k;
				stop_i = 1;
			}
			if(count_vowel == j - 1 && stop_j_pre == 0){
				count_j_pre = k;
				stop_j_pre = 1;
			}
			if(count_vowel == j && stop_j == 0){
				count_j = k;
				stop_j = 1;
			}
		}
		strcpy(output, a);
		if(i == 0){
			for(int k = 0; k <= count_i; k++){
				output[k] = string[k];
			}
		}
		else{
		for(int k = count_i_pre + 1; k <= count_i; k++){
			output[k] = string[k];
		}
		output[strlen(string)] = '\0';
		}
		printf("%s\n", output);
		strcpy(output, a);
		if(j == 0){
			for(int k = 0; k <= count_j; k++){
				output[k] = string[k];
			}
		}
		else{
		for(int k = count_j_pre + 1; k <= count_j; k++){
			output[k] = string[k];
		}
		output[strlen(string)] = '\0';
		}
		printf("%s\n", output);
		strcpy(output, string);
		for(int k = 0; k < strlen(string); k++){
			if(i == 0){
				if(k <= count_i){
					output[k] = '+';
				}
			}
			else if(k <= count_i && k > count_i_pre){
				output[k] = '+';
			}
			if(j == 0){
				if(k <= count_j){
					output[k] = '+';
				}
			}
			else if(k <= count_j && k > count_j_pre){
				output[k] = '+';
			}
		}
		output[strlen(string)] = '\0';
		printf("%s\n", output);
	}
} 
