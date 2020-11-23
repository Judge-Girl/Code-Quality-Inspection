#include<stdio.h>
#include<string.h>

int main(){
	char a[100000];
	unsigned long long x;
	
	int t;
	scanf("%d", &t);
	if(t==0){
		scanf("%s", &a);
		int length = strlen(a);
		int i = 0;
		while(i<length){
			unsigned long long buf1 = 0;
			int shift = 56;
			
			for(int j=0; j<8; j++){
				unsigned long long buf2 = a[i+j];
				buf2 <<= shift-8*j;
				buf1 |= buf2;
			}
			printf("%lld\n", buf1);
			i += 8;
		}
		if(length%8==0){
			printf("0");
		}
	}
	else{
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%llu", &x);
			int left = 0;
			int right = 56;
			for(int j=0; j<8; j++){
				unsigned long long buf = x;
				buf <<= left;
				buf >>= right;
				if(buf==0){
					break;
				}
				printf("%c", buf);
				left += 8;
			}
			
		}
	}
}
