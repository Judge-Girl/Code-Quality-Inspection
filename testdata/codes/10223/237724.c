#include <stdio.h>
#include <string.h>
char word[1000000], temp[2][1000000];
int main(){
	int I, J;
	while(scanf("%s%d%d", word, &I, &J)!=EOF){
		char *pch, *part[3];
		int ct=0, index=0, count=-1;
		int len=strlen(word);
		for(int i=0; i<len; i++){
			if(word[i]=='a'){
				count++;
				if(count==I){
					ct=0;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				if(count==J){
					ct=1;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				index=i+1;
			}
			else if(word[i]=='e'){
				count++;
				if(count==I){
					ct=0;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				if(count==J){
					ct=1;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				index=i+1;
			}
			else if(word[i]=='i'){
				count++;
				if(count==I){
					ct=0;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				if(count==J){
					ct=1;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				index=i+1;
			}
			else if(word[i]=='o'){
				count++;
				if(count==I){
					ct=0;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				if(count==J){
					ct=1;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				index=i+1;
			}
			else if(word[i]=='u'){
				count++;
				if(count==I){
					ct=0;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				if(count==J){
					ct=1;
					for(int j=0; j<index; j++)
						temp[ct][j]='+';
					for(int j=index; j<=i; j++)
						temp[ct][j]=word[j];
					index=i+1;
					for(int j=index; j<len; j++)
						temp[ct][j]='+';
					temp[ct][len]='\0';
				}
				index=i+1;
			}
		}
		printf("%s\n", temp[0]);
		printf("%s\n", temp[1]);
		for(int i=0; i<len; i++){
			if(temp[0][i]=='+'&&temp[1][i]=='+'){
				printf("%c", word[i]);
			}
			else{
				printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}
