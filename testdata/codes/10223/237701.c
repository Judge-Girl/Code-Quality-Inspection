#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Is_vowel(char c){
	char vowel[6] = {'a', 'e', 'i', 'o', 'u'};
	for(int i = 0; i < 6; i++){
		if(c == vowel[i]) return 1;
	}
	return 0;
}
int main(){
	char str[10005];
	memset(str, 0, sizeof(str));
	
	int x, y;
	while(scanf("%s%d%d", str, &x, &y) != EOF){
		int syll_num = 0, syll_idx[10005] = {};
		int len = strlen(str);
		for(int i = 0; i < len; i++){
			if(Is_vowel(str[i]) == 1){
				syll_idx[syll_num] = i;
				syll_num++;
			}
		}
		/*for(int i = 0; i < syll_num; i++){
			printf("%d ", syll_idx[i]);
		}
		puts("");*/
		int len1, prelen1, len2, prelen2;
		//printf("x = %d, y = %d\n", x, y);
		if(x != 0) len1 = syll_idx[x], prelen1 = syll_idx[x-1];
		else len1 = syll_idx[x], prelen1 = -1;
		if(y != 0) len2 = syll_idx[y], prelen2 = syll_idx[y-1];
		else len2 = syll_idx[y], prelen2 = -1;
		//printf("len1 = %d, prelen1 = %d, len2 =  %d, prelen2 =  %d\n",len1,prelen1,len2,prelen2);
		for(int i = 0; i < len; i++){
			if(i <= prelen1 || i > len1){
				putchar('+');
			}
			else putchar(str[i]);
		}
		puts("");
		for(int i = 0; i < len; i++){
			if(i <= prelen2 || i > len2){
				putchar('+');
			}
			else putchar(str[i]);
		}
		puts("");
		for(int i = 0; i < len; i++){
			if((i > prelen1 && i <= len1) || (i > prelen2 && i <= len2)){
				putchar('+');
			}
			else putchar(str[i]);
		}
		puts("");
	}
	return 0;
}
