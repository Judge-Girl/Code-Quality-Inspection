#include <stdio.h>
#include <string.h>
#define lengths 100000000
char s[lengths];
int main(){
	int type;
	scanf("%d",&type);
	if(type == 0){
		
		scanf("%s",s);
		int l = strlen(s);
		//printf("%d\n",l );
		int count = 0,llcount = 0;
		unsigned long long int ULL = 0;
		while(count < l){
			ULL = ULL << 8;
			ULL = ULL | s[count];
			llcount++;
			if(llcount == 8){
				printf("%llu\n",ULL );
				llcount = 0;
				ULL =(unsigned long long int)0;
			}
			count++;
		}
		int i;
		for(i = llcount;i < 8;i++){
			ULL = ULL << 8;
		}
		
		printf("%llu\n",ULL);
	}else{
		int N;
		scanf("%d",&N);
		int i;
		for(i = 0;i < N;i++){
			unsigned long long int ULL;
			scanf("%llu",&ULL);
			char c[8];
			int j;
			for(j = 7;j >= 0;j--){
				c[j] = ULL & (unsigned long long int)255;
				ULL = ULL >> 8;
			}
			printf("%s",c );
		}

	}
	return 0;
}
