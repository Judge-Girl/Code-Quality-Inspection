#include <stdio.h>
#include <string.h>
int main(){
	char k[10000] = {};
	while(scanf("%s", k) != EOF){
		// printf("%s\n", k);
		int i = 0, j = 0; //-1 = token_number
		scanf("%d%d", &i, &j);
		// printf("i = %d, j = %d\n", i, j);

		int len = strlen(k);
		// printf("len = %d\n", len);
		int token_number = 0;
		int token_start_idx[10000/*token_number*/] = {};
		int token_end_idx[10000/*token_number*/] = {};

		int idx = 0;
		int cons = -1;
		while(k[idx] != '\0'){
			if(idx == len-1 && (k[idx] == 'a' || k[idx] == 'e' || k[idx] == 'i' || k[idx] == 'o' || k[idx] == 'u')){
				token_end_idx[token_number] = idx;
				token_number++;
			}else if(idx == len-1){
				cons = token_start_idx[token_number];

			}else if(k[idx] == 'a' || k[idx] == 'e' || k[idx] == 'i' || k[idx] == 'o' || k[idx] == 'u'){
				token_end_idx[token_number] = idx;
				token_number++;
				token_start_idx[token_number] = idx+1;
			}
			// printf("%d\n", idx);
			idx++;
		}

		//i idx
		int i_head = token_start_idx[i];
		int i_tail = token_end_idx[i];
		for(int o=0; o<len; o++){
			if(o >= i_head && o <= i_tail) printf("%c", k[o]);
			else printf("+");
		}
		printf("\n");

		int j_head = token_start_idx[j];
		int j_tail = token_end_idx[j];
		for(int o=0; o<len; o++){
			if(o >= j_head && o <= j_tail) printf("%c", k[o]);
			else printf("+");
		}
		printf("\n");

		for(int o=0; o<len; o++){
			if(o >= i_head && o <= i_tail){
				printf("+");
			}else if(o >= j_head && o <= j_tail){
				printf("+");
			}else{
				printf("%c", k[o]);
			}

		}
		printf("\n");

	}


	return 0;
}
