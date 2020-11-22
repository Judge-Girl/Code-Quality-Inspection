#include <stdio.h>
#include <string.h>
int main(){
	int T;
	scanf("%d", &T);
	char string[100000];
	if(!T){
		scanf("%s", string);
		int length = strlen(string);
		long long int ans = 0;
		int count = 0;
		for(int i = 0; i < length; i++){
			int temp = string[i];
			ans = ans << 8 | temp;
			count++;
			if(count == 8){
				printf("%lld\n",ans);
				ans = 0;
				count = 0;
			}
		}
		ans = ans << 8;
		count++;
		if (count != 0){
			ans <<= (8-count)*8;
			printf("%lld\n",ans);
		}
	}
	else{
		int N;
		scanf("%d", &N);
		int index = 0;
		int temp = 0;
		int count = 0;
		for(int i = 0; i < N; i++){
			long long int num;
			scanf("%lld", &num);
			for(int j = 7; j >= 0; j--){
				temp |= (num >> j*8);
				temp <<= 24;
				temp >>= 24;
				string[index] = temp;
				index++;
				if(temp == 0){
					break;
				}
				temp = 0;
			}
		}
		printf("%s\n",string );
	}
	return 0;
}
