#include <stdio.h>
#include <string.h>
#define MAXS 100000
int main(){
	int type;
	char str[MAXS];
	scanf("%d",&type);
	if(type==0)
	{scanf("%s",str);
		int length=strlen(str);

		long long int arr[length/8+1];
		int cnt=0;
		int tempcnt=0;
		arr[0]=0;
		for(int i=0;i<length+1;i++)
		{
			if(str[i]=='\0')
			{arr[cnt]=arr[cnt]<<8*(7-tempcnt);break;}
		
			arr[cnt]+=(long long int)(str[i]);
			tempcnt++;
			if(tempcnt==8)
			{cnt++;tempcnt=0;arr[cnt]=0;continue;}
			arr[cnt]=arr[cnt]<<8;
			

			
			
			
			
			
			
			
		}
	for(int i=0;i<cnt+1;i++)
	{
		printf("%lld\n",arr[i]);
		
	}
	}
	else if(type==1)
	{int n;
	scanf("%d",&n);
	long long int num[n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&num[i]);
		
	}
	int cnt=0;
		for(int i=0;i<n;i++)
		{	for(int j=0;j<8;j++)
			{if(((num[i]&((long long)(255)<<56))>>56)!=0)
				str[cnt]=(char)((num[i]&((long long)(255)<<56))>>56);
			else
			{str[cnt]='\0';goto END;}
				num[i]=num[i]<<8;
				cnt++;
				
				
				
			}
		}	
		
		str[strlen(str)]='\0';
END:		printf("%s",str);
	}
	
	return 0;
	
	
}
