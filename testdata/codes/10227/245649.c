#include <stdio.h>
#include <string.h>

int main(){
	int tYpe;
	char OuO[100001]={'\0'};
	long long int o3o[12501]={0};
	scanf("%d",&tYpe);
	if(tYpe){
		int nUm;
		scanf("%d",&nUm);
		for(int i=0;i<nUm;i++)
			scanf("%lld",&o3o[i]);
		for(int i=0;i<nUm;i++){
			for(int ii=0;ii<8;ii++){
				OuO[i*8+ii]=(char)((o3o[i])>>(56-ii*8));
			}
		}
		printf("%s",OuO);
	}
	else{
		scanf("%s",OuO);
		int nUm=strlen(OuO)/8+1;
		for(int i=0;i<nUm;i++){
			for(int ii=0;ii<8;ii++){
				o3o[i]+=((long long int)OuO[i*8+ii])<<(56-ii*8);
			}
		}
		for(int i=0;i<nUm;i++)
			printf("%lld\n",o3o[i]);
	}
	return 0;
}
