#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d" ,&T);
	char str[100000];
	if(T){	/*array>>string*/
		int n;
		scanf("%d" ,&n);
		int y,z;
		for(y=0;y<n;y++){
			long long num;
			scanf("%lld", &num);
			for(z=0;z<8;z++){
				int move=(7-z)*8;
				unsigned long long test=-1;
				str[y*8+z]=(num>>move)&(test>>move);
			}
		}
		str[y*8+z]=0;
		printf("%s", str);
	}else{	/*string>>array*/
		scanf("%s", str);
		int lenth=strlen(str);
		int ar_l=lenth/8+1;
		long long arr[12500]={0};
		for(int i=0;i<lenth;i++){
			int move=(7-i%8)*8;
			long long m=str[i];
			arr[i/8]+=m<<move;
		}
		for(int k=0;k<(ar_l);k++)
			printf("%lld\n", arr[k]);
	}
	
}

