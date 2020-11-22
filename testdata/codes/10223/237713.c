#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int isvowel(char c)
{
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i'|| c== 'I' ||c=='o'||c =='O'||c == 'u' || c == 'U'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char s[10001];
	char temp[10001];
	int i1,i2;
	while(scanf("%s%d%d",s,&i1,&i2) == 3){
		strcpy(temp,s);
		int len = strlen(s);
		int wherevowel[len];
		for(int i = 0; i<len; i++){
			wherevowel[i] = -1;
		}
		int cnt_vow = 0;
		for(int i = 0; i<len; i++){
			if(isvowel(s[i])){
				wherevowel[i] = cnt_vow;
				cnt_vow++; 
			}
		}
		int i1pos;
		if(i1 == 0){
			for(int i = 0; i<len; i++){
				if(wherevowel[i] == 0){
					i1pos = i;
					
					break;
				}
			}
			for(int i = 0; i<len; i++){
				if(i <= i1pos){
					temp[i] = '+'; 
					printf("%c",s[i]);
				}
				else{
					printf("+");
				}
				
			}
			printf("\n");
		}
		else{
			int pre;
			int recent;
			for(int i = 0; i<len; i++){
				if(wherevowel[i] == i1 -1){
					pre = i;
				}
				else if(wherevowel[i] == i1){
					recent = i;
					break;
				}
			}
			
			for(int i = 0; i<len; i++){
				if(i > pre && i<= recent){
					temp[i] = '+';
					printf("%c",s[i]);
				}
				else{
					printf("+");
				}
			}
			printf("\n");
			
		}
		
		int i2pos;
		if(i2 == 0){
			for(int i = 0; i<len; i++){
				if(wherevowel[i] == 0){
					i2pos = i;
					break;
				}
			}
			for(int i = 0; i<len; i++){
				if(i <= i2pos){
					temp[i] = '+';
					printf("%c",s[i]);
				}
				else{
					printf("+");
				}
				
			}
			printf("\n");
		}
		else{
			int pre;
			int recent;
			for(int i = 0; i<len; i++){
				if(wherevowel[i] == i2 -1){
					pre = i;
				}
				else if(wherevowel[i] == i2){
					recent = i;
					break;
				}
			}
			
			for(int i = 0; i<len; i++){
				if(i > pre && i<= recent){
					temp[i] = '+';
					printf("%c",s[i]);
				}
				else{
					printf("+");
				}
			}
			printf("\n");
			
			
			
		}
		
		for(int i = 0; i<len; i++){
				printf("%c",temp[i]);
			}
		printf("\n");
		
		
		
	}
	return 0;
	
	
}
