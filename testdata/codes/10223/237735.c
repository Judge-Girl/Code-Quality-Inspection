#include <stdio.h>
#include <string.h>
int main(void)
{
	int first ,second;
	char S[10000];
	while(scanf("%s", S) != EOF){
		scanf("%d%d",&first,&second);
		int count = 0,count_location = 0;
		int location[10000];
		while(S[count] != '\0'){
			if(S[count] == 'a' || S[count] == 'e' || S[count] == 'i' || S[count] == 'o' || S[count] == 'u'){
				location[count_location] = count;
				count_location++;
			}
			count++;
		}
		if(first == 0 || second == 0){
			if(first == 0){
				for(int i = 0; i <= location[first]; i++){
					printf("%c", S[i]);
				}
				for(int i = location[first] + 1; i < count;i++){
					printf("+");
				}
				printf("\n");
				for(int i = 0; i <= location[second - 1]; i++){
				printf("+");
				}
				for(int i = location[second - 1] + 1; i <= location[second]; i++){
				printf("%c", S[i]);
				}
				for(int i = location[second] + 1; i < count;i++){
				printf("+");
				}
				printf("\n");
				for(int i = 0; i < count; i++){
					if(i <= location[first] || (i > location[second - 1] && i <= location[second])){
						printf("+");
					}
					else{
						printf("%c", S[i]);
					}
				}
				printf("\n");			
			}
			else if(second == 0){
				for(int i = 0; i <= location[first - 1]; i++){
					printf("+");
				}
				for(int i = location[first - 1] + 1; i <= location[first]; i++){
					printf("%c", S[i]);
				}
				for(int i = location[first] + 1; i < count;i++){
					printf("+");
				}
				printf("\n");
				for(int i = 0; i <= location[second]; i++){
					printf("%c", S[i]);
				}
				for(int i = location[second] + 1; i < count;i++){
					printf("+");
				}
				printf("\n");
				for(int i = 0; i < count; i++){
					if(i <= location[second] || (i > location[first - 1] && i <= location[first])){
						printf("+");
					}
					else{
						printf("%c", S[i]);
					}
				}
				printf("\n");		
			}
		}
		else{
		for(int i = 0; i <= location[first - 1]; i++){
			printf("+");
		}
		for(int i = location[first - 1] + 1; i <= location[first]; i++){
			printf("%c", S[i]);
		}
		for(int i = location[first] + 1; i < count;i++){
			printf("+");
		}
		printf("\n");
		for(int i = 0; i <= location[second - 1]; i++){
			printf("+");
		}
		for(int i = location[second - 1] + 1; i <= location[second]; i++){
			printf("%c", S[i]);
		}
		for(int i = location[second] + 1; i < count;i++){
			printf("+");
		}
		printf("\n");
		for(int i = 0; i < count; i++){
			if((i > location[first - 1] && i <= location[first]) || (i > location[second - 1] && i <= location[second])){
				printf("+");
			}
			else{
				printf("%c", S[i]);
			}
		}
		printf("\n");
		}
	}
}
