#include<stdio.h>
#include<string.h>

#define STRLEN 200000
#define MAXNUM 22500

void type0(char input[STRLEN])
{
	long long output[MAXNUM], buff = 0;
	int len = strlen(input), count = 0, shift = 64;
	for(int i = 0; i < len; i++){
		shift-=8;
		buff = input[i];
		buff<<=shift;
		output[count]+=buff;
		if(i%8==7){
			count++;
			shift=64;
		} 
	}
	
	if(len%8==0){
		output[count] = 0;
	}	
	count++;
	for(int i = 0; i < count; i++)
		printf("%lld\n", output[i]);
}

void type1(int N)
{
	
	for(int i = 0; i < N; i++){
		unsigned long long input, test = 0;
		test=~test;
		test>>=56;
		test<<=56;
		scanf("%lld", &input);
		//printf("%lld\n", input);
		int shift = 56;
		
		for(int j = 0; j < 8; j++){
			char output = 0;
			long long buff = 0;
			buff=(input&test);
			buff>>=shift;
			test>>=8;
			output+=buff;
			if(shift>0)	shift-=8;
			
			if(output)
				printf("%c", output);
			
		}
		
	}
}


int main()
{
	int type;
	scanf("%d",&type);
	//printf("%d\n", type);
	char input[STRLEN];

	if(type==0){
		while(scanf("%s", input)!=EOF){
			type0(input);
		}
	}else{
		int N;
		scanf("%d", &N);
		type1(N);
	}

	return 0;
}
