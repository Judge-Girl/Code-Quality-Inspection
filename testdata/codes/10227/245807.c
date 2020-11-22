#include <stdio.h>
#define len 100000

int main(){
	int T;
	scanf("%d", &T);
	char S[len];
	long long int llu=0;
	if(T==0){
		while(scanf("%s", S)!=EOF){
			int i;
			for(i=0; S[i]!='\0'; i++){
				if(i>0&&i%8==0){
					printf("%lld\n", llu);
					llu=0;
				}
				llu=llu<<8;
				llu|=S[i];
			}
			if(i%8==0){
				printf("%lld\n", llu);
				llu=0;
				printf("%lld\n", llu);
			}
			else{
				while(i%8!=0){
					llu=llu<<8;
					i++;
				}
				printf("%lld\n", llu);
				llu=0;
			}
		}
	}
	if(T==1){
		int size;
		long long int test8bit=255;
		test8bit=test8bit<<55;
		scanf("%d", &size);
		for(int i=0; i<size; i++){
			scanf("%lld", &llu);
			int j;
			for(j=0; j<8; j++){
				S[j]=(llu&test8bit)>>56; 
				llu=llu<<8;
			}
			printf("%s", S);
		}
	}
	return 0;
}
