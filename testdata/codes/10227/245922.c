#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	if(T == 0){
		
		char S[100000];
		
		scanf("%s",S);
		
		int len = strlen(S)+1;
		int num = len / 8;
		
		
		long long int result[12500] = {0};
		if(len % 8 == 0){
			for(int i = 0; i<num; i++){
				for(int j = 0; j<8; j++){
					result[i] += (long long)(S[i*8+j] & 255) << (56 - 8 * j);
				}
			
			}
	
		
			for(int i = 0; i<num; i++){
				printf("%lld\n",result[i]);
				}
		}
		else{
		
		for(int i = 0; i<num+1; i++){
			for(int j = 0; j<8; j++){
				result[i] += (long long)(S[i*8+j] & 255) << (56 - 8 * j);
			}
			
		}
	
		
		for(int i = 0; i<num+1; i++){
			printf("%lld\n",result[i]);
		}
	}
	}
	else if(T == 1){
		int N;
		long long int store[12500];
		scanf("%d",&N);
		for(int i = 0; i<N; i++){
			scanf("%lld",&store[i]);
		}
		for(int i = 0; i<N; i++){
			for(int j = 0; j<8; j++){
				if((char)(store[i] >> (56-8*j)) == 0){
					break;
				}
				printf("%c",(char)(store[i] >> (56-8*j)));
			}
		}
		
	}
		
	
	
	return 0;
}
