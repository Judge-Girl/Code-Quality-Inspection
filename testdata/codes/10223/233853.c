#include <stdio.h>
#include <string.h>
int isVowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
		return 1;
	}
	else
		return 0;
}


int main(){
	char str[10000];
	while(scanf("%s", str)!=EOF){
		int len = strlen(str);
		int shift0, shift1;
		scanf("%d %d", &shift0, &shift1);
		
		
		int index0, index1;
		int vowel_index =  -1;
		for(int i=0; i<len; i++){
			if(isVowel(str[i])){
				vowel_index++;
				if(vowel_index == shift0)
					index0 = i;
				else if(vowel_index == shift1)
					index1 = i;
			}
		}
		
		char str0[len+1], str1[len+1];
		memset(str0, '+', len*sizeof(char));
		memset(str1, '+', len*sizeof(char));
		str0[len]='\0';
		str1[len]='\0';
		
		str0[index0] = str[index0];
		str[index0] = '+';
		index0--;
		while(!isVowel(str[index0]) && index0>=0){
			str0[index0] = str[index0];
			str[index0] = '+';
			index0--;
		}
		printf("%s\n", str0);
		
		str1[index1] = str[index1];
		str[index1] = '+';
		index1--;
		while(!isVowel(str[index1]) && index1>=0){
			str1[index1] = str[index1];
			str[index1] = '+';
			index1--;
		}
		printf("%s\n", str1);
		printf("%s\n", str);
	}
}
