#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	char name[32][32], ins[3][32], vins[4][32] = {"earns", "spends", "gives", "becomes"}, *q;
	int  i, j, k, l, m, money[n];
	for(i = 0; i < n; i++){
		scanf("%s", name[i]);
		scanf("%d", &money[i]);
	}
	
	while(scanf("%s", ins[0]) != EOF){
		for(i = 0; i < n; i++){
			if(strcmp(name[i], ins[0]) == 0){
				break;
			}
		}
		if(i == n){
			scanf("%s", ins[1]);
			while(isalpha(ins[1][0]) > 0){
				scanf("%s", ins[1]);
			}
			continue;
		}
		scanf("%s", ins[1]);
		for(j = 0; j < 4; j++){
			q = strstr(ins[1], vins[j]);
			if(q != NULL){
				break;
			}
		}
		if(j == 4){
			scanf("%s", ins[1]);
			while(isalpha(ins[1][0]) > 0){
				scanf("%s", ins[1]);
			}
			continue;
		}
		switch(j){
			case 0:{
				scanf("%d", &k);
				money[i] += k;
				break;
			}
			case 1:{
				scanf("%d", &k);
				if(money[i] >= k)
				money[i] -= k;
				break;			
				}
			case 2:{
				scanf("%s", ins[2]);
				for(l = 0; l < n; l++){
					if(strcmp(name[l], ins[2]) == 0){
						break;
					}
				}
				if(l == n){
					scanf("%d", &k);
				}
				else{
					scanf("%d", &k);
					if(money[i] >= k){
					
					money[i] -= k;
					money[l] += k;
				}
				}
				break;
			}
			case 3:{
				scanf("%d", &k);
				money[i] = k;
				break;
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("%s %d", name[i], money[i]);
		if(i < n-1){
			printf("\n");
		}
	}
}

