#include <stdio.h>
#include <string.h>

int main(){
	char word[10001] = "";
	while(scanf("%s" , word) != EOF){
		int one , two , point[10001] = {} , n = 0;
		scanf("%d%d" , &one , &two);
		for(int i = 0 ; i < strlen(word); i ++){
			point[n] = strcspn(&word[i] , "aeiou") + i;
			n ++;
			i += strcspn(&word[i] , "aeiou");
		}
		char outone[10001] = "" , outtwo[10001] = "";
		for(int i = 0 ; i < strlen(word) ; i ++){
			outone[i] = '+';
			outtwo[i] = '+';
		}
		char temp[10001];
		strcpy(temp , outone);
		if(one == 0){
			strncpy(outone , word , point[one] + 1);
			strncpy(word , temp , point[one] + 1);
		}
		else{
			strncpy(&outone[point[one - 1] + 1] , &word[point[one - 1] + 1], point[one] - point[one - 1]);
			strncpy(&word[point[one - 1] + 1], temp , point[one] - point[one - 1]);
		}
		if(two == 0){
			strncpy(outtwo , word , point[two] + 1);
			strncpy(word , temp , point[two] + 1);
		}
		else{
			strncpy(&outtwo[point[two - 1] + 1] , &word[point[two - 1] + 1], point[two] - point[two - 1]);
			strncpy(&word[point[two - 1] + 1], temp , point[two] - point[two - 1]);
		}
		printf("%s\n%s\n%s\n", outone , outtwo , word);
	}
	return 0;
}
