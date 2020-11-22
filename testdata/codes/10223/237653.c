#include <stdio.h>
#include <string.h>

int main()
{
	char input[10000];
	int I, J;
	while(scanf("%s %d %d", input, &I, &J) != EOF){
		int arr[10000] = {0};
		int count = 0;
		int len = strlen(input);
		for(int i = 0; i < len; i ++){
			arr[i] = count;
			if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
				count ++;
			}
		}

		for(int i = 0; i < len; i ++){
			if(arr[i] == I){
				printf("%c", input[i]);
			}else{
				printf("+");
			}
		}
		printf("\n");
		for(int i = 0; i < len; i ++){
			if(arr[i] == J){
				printf("%c", input[i]);
			}else{
				printf("+");
			}
		}
		printf("\n");
		for(int i = 0; i < len; i ++){
			if(arr[i] != I && arr[i] != J){
				printf("%c", input[i]);
			}else{
				printf("+");
			}
		}
		printf("\n");
	}
}
