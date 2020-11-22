#include<stdio.h>
#include<string.h>
int main(void){
	int task;
	scanf("%d",&task);
	char string[100000];
	long long int number=0;
	char str[8];
	switch(task){
		case 0:
		scanf("%s",string);
		int length=strlen(string);
		int times=length/8+1;
		for(int i=0;i<times;i++){
			int j;
			for(j=i*8;j<(i+1)*8&&j<length+1;j++){
				number<<=8;
				number+=string[j];				
			}
			if(i==times-1){
				for(int k=length+1;k<times*8;k++){
					number<<=8;
				}
			}
			printf("%lld\n",number);
			number=0;
		}
		break;
		case 1:
		while(scanf("%lld",&number)!=EOF){
			int bits=64;
			for(int i=0;i<8;i++){
				bits-=8;
				str[i]=number>>bits;
				number<<=(64-bits);
				number>>=(64-bits);
			}
			for(int i=0;i<8;i++){
				if(str[i]!='\0')printf("%c",str[i]);
				else break;
			}
		}
		break;
	}
}
