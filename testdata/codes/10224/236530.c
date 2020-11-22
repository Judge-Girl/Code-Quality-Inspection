#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char subject[32],object[32],verb[32];
char user[32][32];
int money[32];
char *v[4]={"earns","spends","gives","becomes"};

int main(){

	int N,i,j,ins,S,O,l,amount;
	

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%s",user[i]);
		scanf("%d",&money[i]);
	}
	
	while(scanf("%s",subject)!=EOF){
	
		scanf("%s",verb);
		if(strstr(verb,v[2])!=NULL)
		scanf("%s",object);
		scanf("%d",&amount);
		
		/*subject*/
		l = 0;
		for(i=0;i<N;i++)
			if(strcmp(user[i],subject)==0)
				{l = 1; S = i;}
		if(l==0) continue;

		/*verb*/
		l = 0;
		for(i=0;i<4;i++)
			if(strstr(verb,v[i])!=NULL)
				{l = 1; ins = i;}
		if(l==0) continue;

		/*object*/
		if(ins==2){
		l = 0;
		for(i=0;i<N;i++)
			if(strcmp(user[i],object)==0)
				{l = 1; O = i;}
		if(l==0) continue;}


		switch(ins){
			case 0:
				money[S] += amount;
			break;

			case 1:
				if(money[S] >= amount) money[S] -= amount;
			break;

			case 2:
				if(money[S] >= amount){
					money[S] -= amount;
					money[O] += amount;
				}
			break;

			case 3:
				money[S] = amount;
			break;
		}

	}

	/*output*/
	for(i=0;i<N;i++)
		printf("%s %d\n",user[i],money[i]);


	return;
}

