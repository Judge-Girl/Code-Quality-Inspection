#include<stdio.h>
#include<string.h>
#include<ctype.h>
char word[10000] = {'\0'};
int isvowel(char word){
	if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u')
		return 1;
	else
		return 0;
}


int main(void)
{
	int first,second;
	char vowel[6] = {'a','e','i','o','u','\0'};
	while(scanf("%s%d%d",word,&first,&second) != EOF){
		int nowvow1 = -1;
		int prevowloc1 = -1;
		int nowvowloc1 = -1;
		int lens = strlen(word);
		for(int i = 0 ; i < lens ; i++){
			if(isvowel(word[i])){
				prevowloc1 = nowvowloc1;
				nowvowloc1 = i;
				nowvow1++;
			}

			if(nowvow1 == first){
				//printf("pre = %d now = %d\n",prevowloc1,nowvowloc1);
				for(int j = 0 ; j <= prevowloc1 ; j++)
					printf("+");
				for(int j = prevowloc1 + 1 ; j <= nowvowloc1 ; j++)
					printf("%c",word[j]);
				for(int j = nowvowloc1 + 1 ; j < lens ; j++)
					printf("+");
				printf("\n");
				break;
			}
		}
		int plusnum2 = 0;
		int nowvow2 = -1;
		int prevowloc2 = -1;
		int nowvowloc2 = -1;
		for(int i = 0 ; i < lens ; i++){
			if(isvowel(word[i])){
				prevowloc2 = nowvowloc2;
				nowvowloc2 = i;
				nowvow2++;
			}
			if(nowvow2 == second){
				//printf("pre = %d now = %d\n",prevowloc2,nowvowloc2);
				for(int j = 0 ; j <= prevowloc2 ; j++)
					printf("+");
				for(int j = prevowloc2 + 1 ; j <= nowvowloc2 ; j++)
					printf("%c",word[j]);
				for(int j = nowvowloc2 + 1 ; j < lens ; j++)
					printf("+");
				printf("\n");
				break;
			}
		}
		for(int i = 0 ; i < lens ; i++)
			if((i > prevowloc1 && i <= nowvowloc1)||(i > prevowloc2 && i <= nowvowloc2))
				printf("+");
			else
				printf("%c",word[i]);
		printf("\n");
	}
}
