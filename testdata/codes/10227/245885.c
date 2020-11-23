#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char word[100000];
void printbit(unsigned long long int A){
	for(int i = 63; i >= 0;i--){
		printf("%lld",A >> (unsigned long long)i & (unsigned long long)1);
	}
	printf("\n");
}
int main()
{
	int type;scanf("%d",&type);
	if(type == 0){
		scanf("%s",word);
		unsigned long long ans = 0;
		int index = 0;
		for(int i = 0;i < strlen(word);i++){
			ans += word[i];
			index++;
			if(index >= 8){
				printf("%llu\n",ans);
				index = 0;ans = (unsigned long long)0;
			}
			else ans <<= 8;
		}
		if(index == 0)printf("0\n");
		if(index > 0){
			ans <<= (7-index) * 8;
			printf("%llu\n",ans);
		}
	}
	else{
		int N;scanf("%d",&N);
		unsigned long long int in;
		for(int i = 0;i < N;i++){
			scanf("%lli",&in);
			for(int j = 0;j < 8;j++){
				char c = in >> (7-j) * 8 & 255;
				if(c != '\0')printf("%c",c);
			}
		}
		printf("\n");
	}
	return 0;
}
