#include <stdio.h>
#include <string.h>
int main(){
	char table[5] = {'a','e','i','o','u'};
	char word[10001];
	int a,b;
	while(scanf("%s%d%d",word,&a,&b)!=EOF){
       int start[10001], end[10001];
       int len = strlen(word);
       int count = 0;
       for (int i = 0; i < len ; ){
       	   char* min;
       	   int flag = 1;
       	   for (int j = 0; j < 5; j++) {
                char* ptr = strchr(&word[i], table[j]);
                if (flag && ptr != NULL) {
                	min = ptr;
                	flag = 0;
                }
                else if (flag==0 && ptr!=NULL){
                	if (ptr-word < min - word) min = ptr;
                }
       	   }
       	   if(flag==0){
               start[count] = i;
               end[count] = min - word;
               count++;
               i = min - word+1;
       	   }
       	   else break;
       }
       for (int i = 0; i < start[a];i++){
       	   printf("+");
       }
       for(int i = start[a]; i <= end[a];i++){
           printf("%c", word[i]);
       }
       for(int i = end[a]+1 ; i < len;i++){
           printf("+");
       }
       puts("");
       for (int i = 0; i < start[b];i++){
       	   printf("+");
       }
       for(int i = start[b]; i <= end[b];i++){
           printf("%c", word[i]);
       }
       for(int i = end[b]+1; i < len;i++){
       	   printf("+");
       }
       puts("");
       for(int i = 0; i < len;i++){
       	   if((i >= start[a] && i <= end[a]) || (i >= start[b] && i <= end[b])){
              printf("+");
       	   }
       	   else{
       	   	  printf("%c",word[i]);
       	   }
       }
       puts("");
	}
	return 0;
}
