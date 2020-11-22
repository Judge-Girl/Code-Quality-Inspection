#include <stdio.h>
#include <string.h>
 
int main (){
    int t;
    char string[100000]={};
    long long final=0,tmp;
    int num,c=7;
    scanf ("%d",&t);
    if (t==0){
        scanf ("%s",string); 
        int len = strlen(string);
        for (int i=0;i<len;i++){
        	tmp = string[i];
        	num = 8*c;
        	c=c-1;
        	tmp<<=num;
        	final|=tmp;
        	if (c==-1){
        		printf ("%lld\n",final);
        		c=7;
        		final=0;
			}
			if (i==len-1){
				printf ("%lld\n",final);
			}
		}
    }
    else if (t==1){
    	int n;
    	long long int numsix;
    	int charval;
    	int index=0;
    	scanf ("%d",&n);
    	for (int i=0;i<n;i++){
    		scanf ("%lld",&numsix);
    		for (int j=8;j>=1;j--){
    			int compare_8bit=0xff;
    			charval = (numsix>>(8*(j-1)))&compare_8bit;
    			if(charval!=0){
    				string[index]=charval;
    				index++;
				} 
				if (numsix==0){
					string[index]='\0';
					break;
				}
			}
		}
		printf ("%s\n",string);
	}
    return 0;
}
