#include <stdio.h>
#include <string.h>

char temp[10000][4000];

int main(){
	char input[10000];
	int i,j;
	char vowels[5] = {'a','e','i','o','u'};
	int index_1, index_2;

	while(scanf("%s",input) != EOF){

		scanf("%d%d",&index_1,&index_2);

		memset(temp,0,sizeof(temp));

		int length = strlen(input);

		int found = 0;
		int count_letters = 0;
		int count_index = 0;

		int start_index[10000] = {0};

		for(i=0;i<length;i++){
			for(j=0;j<5;j++){
				if(input[i] == vowels[j]){
					found = 1;
					break;
				}
			}
			if(found == 1){
				temp[count_index][count_letters] = input[i];
				count_letters++;
				temp[count_index][count_letters] = '\0';
				start_index[count_index] = i;
				count_index++;
				count_letters = 0;
				found = 0;
			}
			else{
				temp[count_index][count_letters] = input[i];
				count_letters++;
			}
		}

		int length_1 = strlen(temp[index_1]);
		int length_2 = strlen(temp[index_2]);

		for(i=0;i<length;i++){
			if(i == (start_index[index_1] - length_1 + 1)){
				for(j=0;j<length_1;j++){
					printf("%c",temp[index_1][j]);
				}
				i += length_1 - 1;
			}
			else{
				printf("+");
			}
		}

		printf("\n");

		for(i=0;i<length;i++){
			if(i == (start_index[index_2] - length_2 + 1)){
				for(j=0;j<length_2;j++){
					printf("%c",temp[index_2][j]);
				}
				i += length_2 - 1;
			}
			else{
				printf("+");
			}
		}
		printf("\n");

		for(i=0;i<length;i++){
			if(i == (start_index[index_1] - length_1 + 1) || i == (start_index[index_2] - length_2 + 1)){
				if(i == (start_index[index_1] - length_1 + 1)){
					for(j=0;j<length_1;j++){
						printf("+");
					}
					i += length_1 - 1;
				}
				else{
					for(j=0;j<length_2;j++){
						printf("+");
					}
					i += length_2 - 1;
				}
			}
			else{
				printf("%c",input[i]);
			}
		}

		printf("\n");
	}
}
