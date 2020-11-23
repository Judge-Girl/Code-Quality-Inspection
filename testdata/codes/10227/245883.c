#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	if(T==0){
		char s[100000];
		scanf("%s",s);
		int num_of_lli=strlen(s)/8+1;
		long long int lli[12500]={};
		for(int i=0;i<=strlen(s);i++){
			int lli_index=i/8;
			long long int shift_left=(long long int)1<<(56-(i%8)*8);
			lli[lli_index]+=s[i]*shift_left;
		}
		for(int i=0;i<num_of_lli;i++){
			printf("%lld\n",lli[i]);
		}
	}
	else if(T==1){
		int N;
		scanf("%d",&N);
		long long int lli[N];
		char s[100000]={};
		int s_index=0;
		for(int i=0;i<N;i++){
			scanf("%lld",&lli[i]);
			for(int j=0;j<8;j++){
				long long int shift_right=(long long int)1<<(56-(j%8)*8);
				long long int character=(lli[i]/shift_right)%256;
				for(int k=0;k<8;k++){
					long long int check_bit=(long long int)1<<k;
					if((character&check_bit)>(long long int)0){
						s[s_index]+=((char)1<<k);
					}
				}
				s_index++;
			}
		}
		printf("%s",s);
	}
	
	
	
	
	return 0;
}
