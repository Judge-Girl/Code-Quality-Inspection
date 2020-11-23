#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char S[10001];
    char S1[10001];
	char A[10001];
	char B[10001];

	char* V = "aeiou";

	int f, s,l;

	while(scanf("%s", S) != EOF){
		scanf("%d",&f); scanf("%d",&s);

		l = strlen(S);
		memset(A,'+',l);
		memset(B,'+',l);

		memset(S1,'\0',10001);
		strcpy(S1,S);

//first
		int n = strcspn(S,V); 
		int n1;
		for(int i = 0 ; i < f-1 ; i++){
			n = n+1+strcspn(S+n+1, V);
		}

		if(f != 0)
			n1 = n+1+strcspn(S+n+1,V); //Alert
		else{
			n1 = n;
			n = -1;}
		for(int i =  n+1 ; i <= n1 ; i++){
			A[i] = S[i];
			S1[i] = '+';
		}
//second
		n = strcspn(S,V); 
		for(int i = 0 ; i < s-1 ; i++){
			n = n+1+strcspn(S+n+1, V);
		}
		
	if(s != 0)
			n1 = n+1+strcspn(S+n+1,V); //Alert
		else{
			n1 = n;
			n = -1;}

		for(int i =  n+1 ; i <= n1 ; i++){
			B[i] = S[i];
			S1[i] = '+';
		}

		printf("%s\n",A);
		printf("%s\n",B);
		printf("%s\n",S1);
		memset(S,'\0',10001);
		memset(A,'\0',10001);
		memset(B,'\0',10001);





		/*
		printf("%d\n", l);
		printf("%s\n",A);
		*/

	}
	return 0;
}
