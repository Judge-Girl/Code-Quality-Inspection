#include <stdio.h>
#include <string.h>

int main(){
	int cmd;
	scanf("%d" , &cmd);
	if(cmd){
		int len;
		scanf("%d" , &len);
		for(int i = 0 ; i < len ; i ++){
			unsigned long long n;
			scanf("%llu" , &n);
			for(int j = 0 ; j < 8 ; j ++){
				if(n != 0){
				printf("%c", (char)(n >> 56));
				n <<= 8;
				}
				else
					break;
			}
		}
		printf("\n");
	}
	else{
		unsigned long long array[12500] = {0};
		char s[100000] = "";
		scanf("%s" , s);
		int l = strlen(s) , t = 0 ;
		for(int i = 0 ; i < l ; i ++){
			array[t] |= (unsigned long long)s[i] << ((7 - (i % 8)) * 8) ;
			if(i % 8 == 7)
				t ++;
		}
		for(int i = 0 ; i <= t ; i ++){
			printf("%llu\n", array[i]);
		}
	}
	return 0;
}
