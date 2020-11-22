#include <stdio.h>
#include <string.h>
char s2[10000],s3[10000];
char s[10000];
int indexl[10000];
int main(){
	int a,b;
	while(scanf("%s%d%d",s,&a,&b) != EOF){
		int l = strlen(s);
		int i;
		int index_count = 0;
		for(i = 0;i < l;i++){
			if(s[i] == 'a' || s[i] == 'e' || s[i] =='i' || s[i] == 'o' || s[i] == 'u'){
				indexl[index_count] = i;
				index_count++;
			}
		}
		/*for(i = 0;i < index_count;i++){
			printf("%d\n",index[i] );
		}
		printf("a %d\n",a );*/
		
		

		for(i = l-1;i >= 0;i--){
			if(i  <= indexl[a] && a == 0){
				s2[i] = s[i];
			}else if(i <= indexl[a] && i > indexl[a-1]){
					s2[i] = s[i];
			}else{
					s2[i] = '+';
			}	
		}
		for(i = 0;i < l;i++){
			printf("%c",s2[i] );
		}
		printf("\n");
		for(i = l-1;i >= 0;i--){
			if(i <= indexl[b] && b == 0){
				s3[i] = s[i];
			}else if(i <= indexl[b] && i > indexl[b-1]){
				s3[i] = s[i];
			}else{
				s3[i] = '+';
			}	
		}
		for(i = 0;i < l;i++){
			printf("%c",s3[i] );
		}
		printf("\n");

		for(i = 0;i<l;i++){
			if(s2[i] == '+' && s3[i] == '+'){
				printf("%c",s[i]);
			}else{
				printf("+");
			}
		}
		printf("\n");
	}
}
