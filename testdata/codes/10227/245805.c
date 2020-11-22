#include <stdio.h> 
#include <string.h> 

void print_bits(unsigned long long n, int s){
	for (int i = s; i >= 0; --i){
		if(n & (1ULL << i)) printf("1");
		else printf("0");
	}
	puts("");
}

void compose_64bit(){
	char S[100000]; scanf("%s", S);
	char *ptr = &S[0];
	int ctr = 0;
	long long int printNum = 0;

	while(1){
		printNum <<= 8; 
		for (int i = 7; i >= 0; --i){
			if(*ptr & (1 << i)) printNum |= (1LL << i);
		}
		ctr++;
		if(ctr == 8){
			//print_bits(printNum, 64);
			printf("%lld\n", printNum);
			printNum = 0;
			ctr = 0;
		}

		ptr++;
		if(*ptr == '\0'){
			if(ctr != 8){
				printNum <<= ((8-ctr)*8);
				//print_bits(printNum, 64);
				printf("%lld\n", printNum);
			}
			break;
		}
	}
}

int decompose_64bit(){
	int N; scanf("%d", &N);
	long long int num;

	for (int i = 0; i < N; ++i){
		scanf("%lld", &num);
		//print_bits(num, 64);
		for (int j = 8; j > 0; --j){ //scan bytes
			int ctr = 7;
			char ch = '\0';
			for (int k = 0; k < 8; ++k){//scan bits
				//printf("    %d\n", (j*8-1)-k);
				if(num & (1LL << (j*8-1)-k)){
					ch |= (1 << ctr);
				} 
				ctr--;
			}
			//print_bits(ch, 8);
			if(ch == '\0')
				return 1;
			printf("%c", ch);
		}
	}
	return 0;
}


int main(){
	int task; scanf("%d", &task);
	if(task == 0)
		compose_64bit();
	else
		decompose_64bit();

	return 0;
}
