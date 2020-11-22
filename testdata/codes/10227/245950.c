#include <stdio.h>
#include <string.h> 
int main(){
	int T;
	scanf("%d", &T);
	if(T == 0){
		char S[100000] = {};
        scanf("%s", S);
        //
        // printf("%s\n", S);
        int len = strlen(S);
        len += 1;// /0
        // printf("len = %d\n", len);
        //
        int times = len / 8;
        if(len % 8 != 0) times++;
        // printf("times = %d\n", times);
 
        for(int i=0; i<times; i++){
            unsigned long long temp64 = 0, output = 0;
            for(unsigned long long j=8; j>0; j--){
                temp64 = 0;
                temp64 =  temp64 | (int)S[(i*8)+(8-j)];
                // printf("%c\n", (int)S[(i*8)+(8-j)]);
                // printf("%lld\n", temp64);
                temp64 = temp64 << (unsigned long long)((j-1)*8);
                output |= temp64;
                // printf("%lld\n", output);
            }
            printf("%lld\n", output);
        }

	}else if(T == 1){
		int t = 0;
		scanf("%d", &t);
		while(t--){
			unsigned long long input = 0, temp = 0;
			scanf("%lld", &input);
			int idx = 7;
			char Q[8] = {};
			while(input != 0){
				temp = 0;
				
				
				// printf("%lld\n", (input & 255));
				temp |= (input & 255);
				// printf("%lld\n", temp);
				Q[idx] |= temp;
				// printf("Q[%d] = %c\n", idx, (char)Q[idx]);
				idx--;
				input = input >> (unsigned long long) 8; 
			}
			printf("%s", Q);
			

		}

		// printf("\n");
	}


	return 0;
}
