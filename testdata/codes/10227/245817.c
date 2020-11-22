#include <stdio.h>
#include <string.h>
char string[100010];
long long int arr[12501]={0}, tmp;

int main()
{
	int T, N, i, j;
	scanf("%d", &T);
	if(T == 0){
		scanf("%s", string);
		int len = strlen(string), cnt = len/8 + 1;
		for(i=0; i<len; i++){
			int now = i/8;
			int shift=(8*(7-(i%8)));
			tmp = string[i];
			arr[now] |= tmp << shift;
			//printf("%lld\n", arr[now]);
		}
		for(i=0; i<cnt; i++)
			printf("%lld\n", arr[i]);
	}
	else{
		scanf("%d", &N);
		int count = 0;
		while(N--){
			scanf("%lld", &tmp);
			for(i=0; i<8; i++){
				int shift=(8*(7-(i%8)));
				long long int now = tmp>>shift;
				string[count] = now;
				count ++;
			}
		}
		printf("%s", string);
	}
}

