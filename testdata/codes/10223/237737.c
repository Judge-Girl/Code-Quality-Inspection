#include <stdio.h>
#include <ctype.h>
#include <string.h>
char string[100000];
int main(){
	int a, b;
	while(scanf("%s", string) != EOF){
		int start[10000];
		int end[10000];
		int len = strlen(string);
		int a[2];
		scanf("%d%d",&a[0],&a[1]);
		int total_s = 0;
		int start_i = 0, end_i = 0;
		int flag = -1;
		for(int i = 0; i < len; i++){
			flag = -1;
			if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
				start[total_s] = start_i;
				end[total_s] = i;
				total_s++;
				end_i = i;
				start_i = i+1;
				flag = 0;
			}
		}
		if(end_i < len-1){
			start[total_s] = start_i;
			end[total_s] = len-1;
			total_s++;
		}
		for(int j = 0; j < 2; j++){
			for(int i = 0; i < start[a[j]]; i++){
				printf("+");
			}
			for(int i = start[a[j]]; i <= end[a[j]]; i++){
				printf("%c",string[i]);
				string[i] = '+';
			}
			for(int i = end[a[j]] + 1; i < len; i++){
				printf("+");
			}
			printf("\n");
		}
		printf("%s\n",string);
	}
	return 0;
}
