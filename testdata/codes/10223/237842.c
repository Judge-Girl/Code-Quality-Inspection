//Version 1(version 0: 80 points)
//10223. Mark Syllables.
#include <stdio.h>
#include <string.h>
#define debug 0

int isVowel(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	char string[10001];
	int I, J;
	while( scanf("%s %d %d", string, &I, &J) != EOF )
	{
		#if debug == 1
		printf("\nstring:%s, I:%d, J:%d\n", string, I, J);
		#endif

		//find all vowels and their index
		int IofV[10001], NofV = 0;
		for(int i=0;i < strlen(string);i++)
		{
			if(isVowel(string[i]) == 1)
			{
				IofV[NofV] = i;
				NofV++;
			}
		}

		char s1[10001], s2[10001], s3[10001];	
		
		
		//1st string
		int head1, tail1 = IofV[I];
		if(I == 0)
			head1 = 0;
		else
			head1 = IofV[I-1] + 1;
		//
		for(int i=0;i < strlen(string);i++)
		{
			if(head1 <= i && i <= tail1 )
			{
				s1[i] = string[i];
				//printf("%c", string[i] );
			}
			else
			{
				s1[i] = '+';
				//printf("+");
			}
		}
		s1[strlen(string)] = '\0';
		//printf("\n");

		//2nd string
		int head2, tail2 = IofV[J];
		if(J == 0)
			head2 = 0;
		else
			head2 = IofV[J-1] + 1;
		//
		for(int i=0;i < strlen(string);i++)
		{
			if(head2 <= i && i<= tail2)
			{
				s2[i] = string[i];
				//printf("%c", string[i] );
			}
			else
			{
				s2[i] = '+';
				//printf("+");
			}
		}
		s2[strlen(string)] = '\0';
		//printf("\n");

		//3rd string
		for(int i=0;i < strlen(string);i++)
		{
			if(   ( head1 <= i && i <= tail1 ) || ( head2 <= i && i <= tail2 )   )
			{
				s3[i] = '+';
				//printf("+"); //NOTE: different if...else
			}
			else
			{
				s3[i] = string[i];
				//printf("%c", string[i] );
			}
		}
		s3[strlen(string)] = '\0';
		//printf("\n");

		//Method 2
		printf("%s\n", s1);
		printf("%s\n", s2);
		printf("%s\n", s3);
	} //End all cases while.
	
	return 0;
}

