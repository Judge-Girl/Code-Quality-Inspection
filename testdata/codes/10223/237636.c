#include <stdio.h>
#include <string.h>

int check(char c){
	char table[6] = {"aeiou"};
	int in = 0;
	for(int i = 0; i < 5; i++){
		if(c == table[i]){
			in = 1;
			break;
		}
	}
	return in;
}

int main(){
	char word[10000];
	int n1, n2;
	while(scanf("%s %d %d", word, &n1, &n2) != EOF){
		int n = strlen(word);
		int table[n];
		for(int i = 0; i < n; i++){
			table[i] = 2;
		}
		int amount[2];
		int count = 0;
		for(int i = 0; i < n; i++){
			if(count == n1){
				table[i] = 0;
			}
			if(count == n2){
				table[i] = 1;
			}
			if(check(word[i]) == 1){
				count++;
			}
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				if(table[j] == i){
					printf("%c", word[j]);
				}else{
					printf("+");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
