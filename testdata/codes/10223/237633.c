#include <stdio.h>
#include <string.h>

int main(){

	int i, j;
	int arr[10004] = {0};
	char str[10004] = {'\0'};
	while (scanf("%s%d%d", str, &i, &j) != EOF){
		int now = 0, len = strlen(str);
		for (int k = 0; k < len; k ++){
			arr[k] = now;
			if (str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u') now ++;
		}

		for (int k = 0; k < len; k ++){
			if (arr[k] == i) printf("%c", str[k]);
			else printf("+");
		}
		printf("\n");

		for (int k = 0; k < len; k ++){
			if (arr[k] == j) printf("%c", str[k]);
			else printf("+");
		}
		printf("\n");

		for (int k = 0; k < len; k ++){
			if (arr[k] != i && arr[k] != j) printf("%c", str[k]);
			else printf("+");
		}
		printf("\n");

	}
	return 0;
}
