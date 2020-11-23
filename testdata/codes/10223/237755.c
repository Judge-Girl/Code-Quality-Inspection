#include <stdio.h>
#include <string.h>
int main()
{
	char str[10000+1];
	char ans1[10000+1],ans2[10000+1],ans3[10000+1];
	int a,b,first,second;
	while(scanf("%s%d%d",str,&a,&b)!=EOF){
		int x = a-1, y = b-1;
		int prea = -1, preb = -1, first = 0, second = 0;
		int cnt = 0;
		char vowel[] = {'a','e','i','o','u'};
		for(int i = 0; i < strlen(str); i++){
			for(int j = 0; j < 5; j++){
				if(str[i] == vowel[j]){
					if(x == cnt) prea = i;
					if(y == cnt) preb = i;
					if(a == cnt) first = i;
					if(b == cnt) second = i;
					cnt++;
					break;
				} 
			}
		}
		//printf("prea %d, preb %d, first %d, second %d\n",prea,preb,first,second);
		strcpy(ans1,str);
		strcpy(ans2,str);
		strcpy(ans3,str);
		int len1 = first-prea , len2 = second-preb;
		for(int i = 0 ; i < strlen(str); i++){
			if(i >= prea+1 && i <= first) {
				ans3[i] = '+';
				continue;
			}
			else ans1[i] = '+';
		}
		for(int i = 0 ; i < strlen(str); i++){
			if(i >= preb+1 && i <= second) {
				ans3[i] = '+';
				continue;
			}
			else ans2[i] = '+';
		}
		printf("%s\n%s\n%s\n",ans1,ans2,ans3);
	}
}
