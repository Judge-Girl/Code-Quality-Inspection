#include <stdio.h>
#include <string.h>
void printanswer(unsigned long long int answer){
	unsigned long long int one=1;
	for(int i=0;i<64;i++){
		unsigned long long int temp=answer>>(63-i);
		temp&=one;
		printf("%llu",temp);
	}
	printf("\n");
}
int main(){
	int type; scanf("%d",&type);

	if(type==0){
		char string[100000];
		scanf("%s",string);
		int length= strlen(string);
		int count=7;
		unsigned long long int answer=0;

		for(int i=0;i<length;i++){
			unsigned long long int temp = string[i];
			//printf("temp = ");
			//printanswer(temp);
				int num= count*8;
				//printf("i=%d count=%d ",i,count);
				count--;
				temp=temp<<num;
				answer|=temp;

				//printanswer(answer);
			if( count==-1 && i!=length-1){
				printf("%lld\n",answer);
				count=7;
				answer=0;
			}
			if(i==length-1){
				printf("%lld\n",answer);
			}
		}
		if(length%8==0){
			printf("0\n");
		}
	}
	else if(type==1){
		char output[10000];
		int outcount=0;
		int num; scanf("%d",&num);
		for(int i=0;i<num;i++){
			unsigned long long int input; scanf("%lld",&input);
			//printanswer(input);
			unsigned long long int mask = ((unsigned long long )1<<8)-1;
			for(int i=7;i>=0;i--){
				unsigned long long int temp = input>>(i*8);
				temp&=mask;
				output[outcount]=temp;
				outcount++;
			}
		}
		printf("%s\n",output);
		// printf("\n");
	}
	return 0;
}
