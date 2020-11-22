#include<stdio.h>
#include<string.h>

int n;
char users[40][50];
int balance[40];
const char *ins[]={"earns", "spends", "gives", "becomes"};
int find_user(char *s) {
	int res;
	for(res=0;res<n;res++) {
		if(strcmp(s,users[res])==0)return res;
	}
	return -1; 
}

int find_ins(char *s) {
	int res;
	for(res=0;res<4;res++) {
		if(strstr(s,ins[res])!=NULL)return res;
	}
	return -1;
}

int main() {
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) {
		scanf(" %s %d", users[i], &balance[i]);
	}

	char line[200], *cmd[4];
	char *pch;
	while(fgets(line,200,stdin)) {
		pch=strtok(line, " ");
		i=0;
		while(pch!=NULL && i<4) {
			cmd[i++]=pch;
			pch=strtok(NULL, " ");
		}
		if(pch!=NULL)continue;	//invalid

		int l=find_user(cmd[0]);
		if(l==-1)continue;
		int cmd_id=find_ins(cmd[1]);
		if(cmd_id==-1)continue;
		int amount;
		if(cmd_id==2) {
			int r=find_user(cmd[2]);
			if(r==-1)continue;
			if(sscanf(cmd[3], "%d", &amount)==EOF)continue;	//invalid
			if(balance[l]-amount<0)continue;
			balance[l]-=amount;
			balance[r]+=amount;
		}
		else {
			if(sscanf(cmd[2], "%d", &amount)==EOF)continue;	//invalid
			if(cmd_id==0) {
				balance[l]+=amount;
			}
			else if(cmd_id==1) {
				if(balance[l]-amount<0)continue;
				balance[l]-=amount;
			}
			else {
				balance[l]=amount;
			}
		}
	}

	for(i=0;i<n;i++) {
		printf("%s %d\n",users[i], balance[i]);
	} 

	return 0;
}

