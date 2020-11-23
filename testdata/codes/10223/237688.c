#include<stdio.h>
#include<string.h>
int main(){
	char string[100000]={0};
	while(scanf("%s", string)!=EOF){
		int vplace[100000]={0};
		int n1, n2, p_pos1=-1, pos1=-1, p_pos2=-1, pos2=-1, l, num;
		int i, j;
		scanf("%d %d", &n1, &n2);
		l=strlen(string);
		for(i=0;i<l;i++){
			if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u'){
				vplace[i]=1;
			}
		}
		i=0, num=0;
		while(1){
			//printf("break");
			num+=vplace[i];
			if(n1==0);
			else if(p_pos1==-1 && num==n1) p_pos1 = i;
			if(pos1==-1 && num==n1+1) pos1 = i;
			if(n2==0);
			else if(p_pos2==-1 && num==n2) p_pos2 = i;
			if(pos2==-1 && num==n2+1) pos2 = i;
			i++;
			//printf("%d %d %d %d\n", p_pos1, pos1, p_pos2, pos2);
			if(pos1!=-1 && pos2!=-1 && (p_pos1!=-1 || n1==0) && (p_pos2!=-1 || n2==0)) break;
		}
		for(i=0;i<l;i++){
			if(i<=p_pos1 || i>pos1) printf("+");
			else printf("%c", string[i]);
		}
		printf("\n");
		for(i=0;i<l;i++){
			if(i<=p_pos2 || i>pos2) printf("+");
			else printf("%c", string[i]);
		}
		printf("\n");
		for(i=0;i<l;i++){
			if(i>p_pos1 && i<=pos1) printf("+");
			else if(i>p_pos2 && i<=pos2) printf("+");
			else printf("%c", string[i]);
		}
		printf("\n");
	}
} 
