#include <stdio.h>
#include <string.h>

int main(){
	int sample = 1;
	sample <<= 8;
	int mode;
	scanf("%d", &mode);
	if(mode == 0){
		char data[100001];
		scanf("%s", data);
		int t = strlen(data);
		t++;
		int n = (t / 8);
      	if(t % 8 != 0){
        	n++;
        }
		unsigned long long int ans[n];
		for(int i = 0; i < n; i++){
			ans[i] = 0;
		}
		for(int i = 0; i < t; i++){
			int tar = i / 8, c = data[i];
			ans[tar] = ans[tar] << 8;
			ans[tar] += c;
		}
		
		if(t % 8 != 0){
			ans[n - 1] <<= ((8 - (t%8)) * 8);
		}
		for(int i = 0; i < n; i++){
			printf("%llu\n", ans[i]);
		}
	}else{
		int n;
		scanf("%d", &n);
		unsigned long long int data[n];
		for(int i = 0; i < n; i++){
			scanf("%llu", &data[i]);
		}
		char ans[n * 8];
		int t = n * 8;
		for(int i = 0; i < t; i++){
			int tar = i / 8;
			ans[i] = (data[tar] >> ((7 - i % 8) * 8)) % sample;
			
		}
		printf("%s\n", ans);
	}
	return 0;
} 
