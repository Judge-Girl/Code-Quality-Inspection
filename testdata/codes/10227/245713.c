#include <stdio.h>
#include <string.h>
char string[100000];
int arr[100000][10];
char a[8];
int main(){
	int type;
	int index = 0;
	scanf("%d", &type);
	unsigned long long int answer = 0;
	if (type == 0){
		scanf("%s", string);
		int length = strlen(string);
		for (int i = 0 ; i <= length ; i++){
			if (i % 8 == 0) index++;
			arr[index-1][i%8] = string[i];
		}
		for (int i = 0 ; i < index ; i ++){
			answer = 0ll;
			for (int j = 0 ; j < 8 ; j++){
				answer += arr[i][j];
				if (j != 7) answer <<= 8;
			}
			printf("%lld\n", answer);
		}
	}
	else if (type == 1){
		int times;
		unsigned long long int p = 1;
		unsigned long long int mynum = 0;
		for (int aa = 0 ;aa < 7 ; aa ++){
			p <<= 1;
			p += 1;
		}
		scanf("%d", &times);
		for (int i = 0 ; i < times ; i ++){
			scanf("%lld", &mynum);
			for (int j = 7 ; j >= 0 ; j--){
				answer = (mynum >> j*8);
				a[7 - j] = answer;
			}
			printf("%s", a);
		}
		printf("\n");
	}

	return 0;
}
