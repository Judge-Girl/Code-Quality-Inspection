#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (1<<16) 
char s[MAX];
char ans[MAX];
int pos[10010];
int main()
{
	int u, v, i, j;
	while(scanf("%s%d%d", s, &u, &v) != EOF){
		int l = strlen(s), count = 0;
		strcpy(ans, s);
		ans[l] = '\0';
		for(i=0; i<l; i++){
			if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
				pos[count] = i;
				count ++;
			}
		}
		if(u == 0){
			for(i=0; i<=pos[u]; i++){
				printf("%c", s[i]);
				ans[i] = '+';
			}
			for(;i<l; i++)
				printf("+");
			printf("\n");
		}
		else{
			for(i=0; i<l; i++){
				if(i > pos[u-1] && i <= pos[u]){
					printf("%c", s[i]);
					ans[i] = '+';
				}
				else
					printf("+");
			}
			printf("\n");
		}
		if(v == 0){
			for(i=0; i<=pos[v]; i++){
				printf("%c", s[i]);
				ans[i] = '+';
			}
			for(;i<l; i++)
				printf("+");
			printf("\n");
		}
		else{
			for(i=0; i<l; i++){
				if(i > pos[v-1] && i <= pos[v]){
					printf("%c", s[i]);
					ans[i] = '+';
				}
				else
					printf("+");
			}
			printf("\n");
		}
		printf("%s\n", ans);
	}
	return 0;
}
