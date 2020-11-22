#include<stdio.h>
#include<string.h>
int main(){
	char s[10001]={NULL};
	int s1,s2,c;
	while(scanf("%s",&s)!=EOF){
		int l=strlen(s);
		int sh[10001]={0},st[10001]={0};
		scanf("%d%d",&s1,&s2);
		c=0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u'){
				st[c]=i;
				sh[++c]=i+1;
			}
		}
		for(int i=0;i<sh[s1];i++)printf("+");
		for(int i=sh[s1];i<=st[s1];i++)printf("%c",s[i]);
		for(int i=st[s1]+1;i<l;i++)printf("+");
		printf("\n");
		for(int i=0;i<sh[s2];i++)printf("+");
		for(int i=sh[s2];i<=st[s2];i++)printf("%c",s[i]);
		for(int i=st[s2]+1;i<l;i++)printf("+");
		printf("\n");
		for(int i=0;i<strlen(s);i++){
			if((i>=sh[s2] && i<=st[s2])|| (i>=sh[s1] && i<=st[s1]))printf("+");
			else printf("%c",s[i]);
		}
		printf("\n");
	}
}

