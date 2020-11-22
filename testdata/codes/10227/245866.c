#include<stdio.h>
#include<string.h>
main()
{
int t;
char string[1000000];
scanf("%d",&t);
unsigned long long lnln[12500]={0};
if(t==0)
{
	scanf("%s",string);
	int n;
	int len = strlen(string);
	for(n=0;n<len;n++)
	{	
		lnln[n/8]|=(unsigned long long)string[n]<<8*(7-n%8);
	}
	for(int s=0;s<=len/8;s++)
	{
		printf("%llu\n",lnln[s]);
		lnln[s]=0;
	}
}
else
{	
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%llu",&lnln[i]);
		for(int x=0;x<8;x++)
		{
			string[i*8+x]=(lnln[i]<<(8*x))>>56;
		}
	}
	string[n*8]='\0';
	printf("%s",string);
}

}
