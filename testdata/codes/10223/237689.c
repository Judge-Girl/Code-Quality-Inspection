#include<stdio.h>
#include<string.h>
int main(){
	int a , b;
	char in[10001] = "" , vow[] = "aeiou";
	char *ptr[10000] = {NULL};
	while(scanf("%s" , in) != EOF){
		int l = strlen(in) , num = 0 , step = 1;
		scanf("%d %d" , &a , &b);
		ptr[0] = &in[0];
		for(int i = 0 ; i < l ; i++){
			if(in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u'){
				ptr[step] = &in[i + 1];
				step++;
			}
		}
		for(int i = 0 ; i < l ; i++){
			if(&in[i] < ptr[a]) printf("+");
			else if (&in[i] < ptr[a + 1]){
				printf("%c" , in[i]);
				in[i] = '+';
			}
			else printf("+");
		} //bug
		printf("\n");
		for(int i = 0 ; i < l ; i++){
			if(&in[i] < ptr[b]) printf("+");
			else if (&in[i] < ptr[b + 1]){
				printf("%c" , in[i]);
				in[i] = '+';
			}
			else printf("+");
		} //bug
		printf("\n");
		printf("%s" , in); //bug
		printf("\n");
		
	}
	return 0;
}
