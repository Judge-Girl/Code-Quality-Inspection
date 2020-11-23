#include<stdio.h>
#include<string.h>
int main(){
	int go=1;
	while(go){
		char words[10000];
		int i, j;
		if(scanf("%s %d %d", &words, &i, &j)==EOF)
			break;
		int len=strlen(words);
		char w1[len], w2[len], w3[len];
		int vowel=0;
		for(int q=0;q<len;q++){
			if(vowel==i){
				w1[q]=words[q];
				w2[q]=w3[q]='+';
			}else if(vowel==j){
				w2[q]=words[q];
				w1[q]=w3[q]='+';
			}else{
				w3[q]=words[q];
				w1[q]=w2[q]='+';
			}
			if(words[q]=='a'||words[q]=='e'||words[q]=='i'||words[q]=='o'||words[q]=='u'){
				vowel++;
			}
		}
		for(int g=0;g<len;g++)
			printf("%c", w1[g]);
		printf("\n");
		for(int g=0;g<len;g++)
			printf("%c", w2[g]);
		printf("\n");
		for(int g=0;g<len;g++)
			printf("%c", w3[g]);
		printf("\n");
	}
	return 0;
}
