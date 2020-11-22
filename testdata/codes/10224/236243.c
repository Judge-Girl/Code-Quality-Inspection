#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char name[32][32];
int value[32];
int n;

int find(char a[]){
	for(int i = 0;i<n;i++){
		if(strcmp(name[i], a) == 0){
			return i;
		}
	}
	return -1;
}


int main(){
	
	scanf("%d",&n);
	scanf("\n");
	int k = 0;
	char line[100];
	char word[32][32];
	while(gets(line)){
		int count = 0;
		char *start = line;
		start = strtok(start, " ");
		while(start != NULL){
			strcpy(word[count], start);
			count++;
			start = strtok(NULL, " ");
		}
		//printf("%d\n",count);
		if(count == 2){
			//printf("%s\n",word[0]);
			strcpy(name[k], word[0]);
			value[k] = atoi(word[1]);
			k++;
		}
		else if(count == 3){			
			if(strstr(word[1], "earns") != NULL){
				int idx = find(word[0]);
				int v = atoi(word[2]);
				if(idx != -1){
					value[idx] += v;
				}
			}
			else if(strstr(word[1], "spends") != NULL){				
				int idx = find(word[0]);
				int v = atoi(word[2]);
				if(idx != -1 && value[idx]-v >= 0){
					value[idx] -= v;
				}
			}
			else if(strstr(word[1], "becomes") != NULL){
				int idx = find(word[0]);
				int v = atoi(word[2]);
				if(idx != -1){
					value[idx] = v;
				}
			}
		}
		else if(count = 4){		
			if(strstr(word[1], "gives") != NULL){
				int idx1 = find(word[0]);
				int idx2 = find(word[2]);
				int v = atoi(word[3]);
				if(idx1 != -1 && idx2 != -1 && value[idx1]-v >= 0){
					value[idx1] -= v;
					value[idx2] += v;
				}
			}
		}
	}
	for(int i = 0;i<n;i++){
		printf("%s %d\n",name[i], value[i]);
	}
}
