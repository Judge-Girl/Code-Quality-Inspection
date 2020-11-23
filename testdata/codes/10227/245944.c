#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000
int main () {
	int type;
	scanf("%d", &type);
	
	if(type == 0) {
		char str[MAXSIZE] = {0};
		scanf("%s", str);
		int len = strlen(str);
		unsigned long long int ans= 0, tmp =0;
		int count = 7;
		
		for(int i = 0; i < len; i++) {
			tmp = str[i];
			tmp <<= 8 * count;
			ans |= tmp;
			count--;
			// printf("count %d i %d\n", count, i);
			if(count == -1 && i != len-1) {
				printf("%llu\n",ans);
				count = 7;
				ans = 0;
			}
			else if(i == len-1) {
				printf("%llu\n",ans);
			}
		}
		if(len%8 == 0) printf("0\n");
	}
	else if(type == 1) {
		int size;scanf("%d", &size);
		unsigned long long int number;
		char string[MAXSIZE] = {};
		int count_nol = 0, index = 0;

		for(int i = 0; i < size; i++) {
			scanf("%llu", &number);
			for(int i = 7; i >= 0; i--) {
				unsigned int mask = 255;
				unsigned char ans =  (number >> (8*i)) & mask;
				
				//printf("ans %u\n", ans);
				if(ans != 0) {
					string[index] =  ans;
					index++;
					//printf("%c", ans );
				} 
				if(number == 0) {
					string[index] = '\0';
					break;
				}
			}

		}
		printf("%s",string );
	}

}
