#include<stdio.h>
typedef struct pair{
	int y,x;
}pair;
pair person[2][50000];
long long a_bs(long long k){
	if(k<0)return -k;
	return k;
}int main(){
	int n,out[100000],now=0;
	long long min;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		int kkk=i%2;
		scanf("%d%d",&person[kkk][i/2].x,&person[kkk][i/2].y);
		if(i>0){
			min=1000000000;
			if(kkk==0){
				for(int j=0;j<i/2;j++){
					long long kl=a_bs(person[(i+1)%2][j].x-person[i%2][i/2].x)+a_bs(person[(i+1)%2][j].y-person[i%2][i/2].y);
					if(kl<min)min=kl;
				}out[now++]=min;
			}else{
				for(int j=0;j<i/2+1;j++){
					long long kl=a_bs(person[(i+1)%2][j].x-person[i%2][i/2].x)+a_bs(person[(i+1)%2][j].y-person[i%2][i/2].y);
					if(kl<min)min=kl;
				}out[now++]=min;
			}
		}	
	}char c=13;
	for(int i=0;i<now;i++)printf("%d%c\n",out[i],c);
}

