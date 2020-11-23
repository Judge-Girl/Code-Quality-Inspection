#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char word[10000];
	int first,second;

	char vowel[5] = {'a','e','i','o','u'};
	int vowel_index[10000] = {0};

	while(scanf("%s%d%d",word,&first,&second) != EOF){
		int cnt = 1;
		for(int i = 0;i < strlen(word);i++){
			for(int j =0;j < 5;j++){
				if(word[i] == vowel[j])vowel_index[cnt++] = i;
			}
		}

		int fs = vowel_index[first]+1,fe = vowel_index[first+1];
		int ss = vowel_index[second]+1,se = vowel_index[second+1];
		if(first == 0)fs = 0;if(second == 0)ss = 0;
		char line1[10000],line2[10000],line3[10000];
		memset(line1,0,sizeof(line1));memset(line2,0,sizeof(line2));memset(line3,0,sizeof(line3));
		for(int i = 0;i < strlen(word);i++){
			if(i >=fs && i <= fe)line1[i] = word[i];
			else line1[i] = '+';
			if(i >=ss && i <= se)line2[i] = word[i];
			else line2[i] = '+';
			if((i >=fs && i <= fe) || (i >= ss && i <=se))line3[i] = '+';
			else line3[i] = word[i];
		}
		printf("%s\n%s\n%s\n",line1,line2,line3);

	}

	return 0;
}
