#include <stdio.h>
#include <string.h>
char strings[100001] = {'\0'};
unsigned long long int results[12501] = {0};
unsigned long long int test = 1 ;
int main(){
	int type , i, r = 128;
	int current = -1;
	test = test << 63;
	
	scanf("%d", &type);
	if (type == 0){
		scanf("%s", strings);
		int length = strlen(strings);
		for (i = 0; i < length + 1; i++){
			if (i % 8 == 0){
				current++;
			}
			results[current] = results[current] << 8;
			results[current] += strings[i];
			
		}
		results[current] = results[current] << (8 * (8 - i % 8));
		for (int j = 0; j <= current; j++){
			printf("%llu", results[j]);
			if (j != current)
				printf("\n");
		}
	}
	else if (type == 1){
		int n;
		int finish = 0;
		current = 0;
		int c = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++){
			scanf("%llu", &(results[j]));
		}
		while (finish == 0){
			for (int h = 0; h < 8; h++){
				if (results[current] & test){
					strings[c] += r;
				}
				r /= 2;
				results[current] = results[current] << 1;
			}
			if (strings[c] != '\0'){
				if (c % 8 == 7){
					current++;
				}
				r = 128;
				c++;
			}
			else {
				finish = 1;
			}
		}
		printf("%s", strings);
	}
}
