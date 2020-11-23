#include <stdio.h>
#include <string.h>
int main(){
	char str[10001];
	int x , y;
	int first, second;
	int firsthead, secondhead;
	char vow[] = {'a','e','i','o','u'}; 
	while(scanf("%s %d %d", str, &x, &y) != EOF){
		int count = 0 ;
		int numvow = -1;
		//printf("%d\n",strlen(str));
		/*for (int i = 0; i < strlen(str) ; i++){
			for (int j = 0 ; j < 5 ; j++){
				if (str[i] == vow[j]) numvow++;
			}
		}*/

		for (int i = 0; i < strlen(str) ; i++){
			count ++;
			for (int j = 0 ; j < 5 ; j++){
				if (str[i] == vow[j]){
					numvow++;
					//printf("yes\n");
					//printf("i = %d x = %d\n", i,x);
					if (x == numvow){
						//printf("herex");
						first = i;
						firsthead = i - count+1;
						count = 0;
						break;
					}
					if (y == numvow){
						//printf("herey");
						second = i;
						secondhead = i-count+1;
						count = 0;
						break;
					}
					count = 0;
				}
			}
		}
		char ans1[10000+1];
		char ans2[10000+1];
		char ans3[10000+1];
		int k = strlen(str);
		for (int i = 0 ; i < strlen(str) ; i++){
			ans1[i] = '+';
			ans2[i] = '+';
			ans3[i] = '+';
		}
		for (int i = firsthead ; i <= first; i ++){
			ans1[i] = str[i];
			ans3[i] = str[i];
		}
		for (int i = secondhead ; i <= second; i ++){
			ans2[i] = str[i];
			ans3[i] = str[i];
		}
		for (int i = 0 ; i < strlen(str); i++){
			if (ans3[i] != '+') ans3[i] ='+';
			else ans3[i] = str[i];
		}
		ans1[k] = '\0';
		ans2[k] = '\0';
		ans3[k] = '\0';
		printf("%s\n%s\n%s\n", ans1, ans2, ans3);
	}
	return 0;
}
