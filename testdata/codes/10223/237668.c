#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	int vowel_index[10000];
	while(scanf("%s",s)!=EOF){
		int vi,vj;
		scanf("%d%d",&vi,&vj);
		int vowel_count=0;
		int s_index=0;
		while(s[s_index]!=0){
			if(s[s_index]=='a'||s[s_index]=='e'||s[s_index]=='i'||s[s_index]=='o'||s[s_index]=='u'){
				vowel_index[vowel_count]=s_index;
				vowel_count++;
			}
			s_index++;
		}
		if(vi==0){
			for(int i=0;i<=vowel_index[0];i++){
				printf("%c",s[i]);
				s[i]='+';
			}
			for(int i=vowel_index[0]+1;i<strlen(s);i++){
				printf("+");
			}
		}
		else{
			for(int i=0;i<=vowel_index[vi-1];i++){
				printf("+");
			}
			for(int i=vowel_index[vi-1]+1;i<=vowel_index[vi];i++){
				printf("%c",s[i]);
				s[i]='+';
			}
			for(int i=vowel_index[vi]+1;i<strlen(s);i++){
				printf("+");
			}
		}
		printf("\n");
		if(vj==0){
			for(int i=0;i<=vowel_index[0];i++){
				printf("%c",s[i]);
				s[i]='+';
			}
			for(int i=vowel_index[0]+1;i<strlen(s);i++){
				printf("+");
			}
		}
		else{
			for(int i=0;i<=vowel_index[vj-1];i++){
				printf("+");
			}
			for(int i=vowel_index[vj-1]+1;i<=vowel_index[vj];i++){
				printf("%c",s[i]);
				s[i]='+';
			}
			for(int i=vowel_index[vj]+1;i<strlen(s);i++){
				printf("+");
			}
		}
		printf("\n");
		printf("%s\n",s);
	}
	
	
	
	return 0;
}
