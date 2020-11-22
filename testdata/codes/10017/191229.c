#include<stdio.h>
typedef struct pair{
	int y,x;
}pair;
pair person[2][50000];
int a_bs(int k){
	if(k<0)return -k;
	return k;
}int main(){
	int n,out[100000],now=0,min;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		int kkk=i%2,aaa=i/2;
		scanf("%d%d",&person[kkk][aaa].x,&person[kkk][aaa].y);
		if(i>0){
			min=1000000000;
			if(kkk==0){
				for(int j=0;j<i/2;j++){
					int kl=a_bs(person[(i+1)%2][j].x-person[kkk][aaa].x)+a_bs(person[(i+1)%2][j].y-person[kkk][aaa].y);
					if(kl<min)min=kl;
				}printf("%d\n",min);
			}else{
				for(int j=0;j<i/2+1;j++){
					int kl=a_bs(person[(i+1)%2][j].x-person[kkk][aaa].x)+a_bs(person[(i+1)%2][j].y-person[kkk][aaa].y);
					if(kl<min)min=kl;
				}printf("%d\n",min);
			}
		}	
	}
}

