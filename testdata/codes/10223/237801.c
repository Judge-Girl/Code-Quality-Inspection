#include <stdio.h>
#include <string.h>

int main (){
	char str[10000];
	int pos[10000];
	int f,s;
	int sudah[10000];
	while (scanf ("%s%d%d",str,&f,&s)!=EOF){
		int l = strlen(str);
		//initialize pos into negative
		for (int i=0;i<l;i++)pos[i]=-1;
		for (int i=0;i<l;i++)sudah[i]=0;
		//Find syllable
		int id=-1;
		for (int i=0;i<l;i++){
			if (str[i]=='a'||str[i]=='i'||str[i]=='e'||str[i]=='u'||str[i]=='o')pos[++id]=i;
		}
		//check pos
		//print syl first
		for (int i=0;i<l;i++){
			if (f==0){
				if (i>=0&&i<=pos[f]){
					printf("%c",str[i]);
					sudah[i]=1;
				}
				else printf ("+");
			}
			if (f>0)if(i>pos[f-1]&&i<=pos[f]){
				sudah[i]=1;
				printf("%c",str[i]);
			}
			else printf ("+");	
		}
		printf ("\n");
		//print syl second
		for (int i=0;i<l;i++){
			if (s==0){
				if (i>=0&&i<=pos[s]){
					sudah[i]=1;
					printf("%c",str[i]);
				}
				else printf ("+");
			}
			if (s>0)if(i>pos[s-1]&&i<=pos[s]){
					printf("%c",str[i]);
					sudah[i]=1;				
			}
			else printf ("+");
		}
		printf ("\n");
		//print syl the rest
		for (int i=0;i<l;i++){
			if (sudah[i]==0)printf ("%c",str[i]);
			else printf("+");
		}
		printf ("\n");
	} 
	return 0;
}
