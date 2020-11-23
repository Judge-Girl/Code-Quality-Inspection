#include<stdio.h>
#include<string.h>

int main() {
	char str[10050];
	int a,b;
	int pos[10050];
	while(scanf(" %s %d %d", str, &a, &b)==3) {
		int l=strlen(str);	
		int x=0;
		pos[x++]=0;
		int i;
		for(i=0;i<l;i++) {
			if(strchr("aeiou",str[i])!=NULL)pos[x++]=i+1;
		}
		for(i=0;i<l;i++) {
			char c;
			if(pos[a]<=i&&i<pos[a+1]) {
				c=str[i];
				str[i]='+';
			}
			else c='+';
			putchar(c);
		}
		putchar('\n');
		for(i=0;i<l;i++) {
			char c;
			if(pos[b]<=i&&i<pos[b+1]) {
				c=str[i];
				str[i]='+';
			}
			else c='+';
			putchar(c);
		}
		putchar('\n');
		puts(str);
	}
	return 0;
}
		

