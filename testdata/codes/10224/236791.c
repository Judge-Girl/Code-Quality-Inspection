#include <stdio.h>
#include <string.h>

int de(char decrypt[],char encrypt[]){
	if(strstr(encrypt,"earns")!=NULL)
		strcpy(decrypt,"earns");
	else if(strstr(encrypt,"spends")!=NULL)
		strcpy(decrypt,"spends");
	else if(strstr(encrypt,"gives")!=NULL)
		strcpy(decrypt,"gives");
	else if(strstr(encrypt,"becomes")!=NULL)
		strcpy(decrypt,"becomes");
	else
		return -1;
	return 0;
}

int main(){
	int N,I=0;
	scanf("%d",&N);
	char user[40][40]={'\0'};
	int balance[40]={0};
	for(int i=0;i<N;i++){
		scanf("%s%d",user[i],&balance[i]);
	}
	char inst[210];
	while(fgets(inst,210,stdin)!=NULL){
		char name[210],encrypt[210],anothername[210],decrypt[210];
		int n;
		int nameid=-1,anothernameid=-1;
	#ifdef deb
	printf("%d\n",I);
	I++;
	#endif
		sscanf(inst,"%s%s",name,encrypt);
		for(int i=0;i<N;i++){
			if(strcmp(name,user[i])==0){
				nameid=i;
			}
		}
		if(nameid==-1)
			continue;
		if(de(decrypt,encrypt)==-1)
			continue;
		if(strstr(decrypt,"gives")!=NULL){
			//printf("yes?");
			sscanf(inst,"%s%s%s%d",name,encrypt,anothername,&n);
			for(int i=0;i<N;i++){
				if(strcmp(anothername,user[i])==0){
					anothernameid=i;
					}
			}
			if(anothernameid==-1)
				continue;
			#ifdef deb
			printf("%s %s %s %d\n",name,decrypt,anothername,n );
			#endif
		}
		else{
			sscanf(inst,"%s%s%d",name,encrypt,&n);
			#ifdef deb
			printf("%s %s %d\n",name,decrypt,n );
			#endif
		}

		if(strstr(decrypt,"earns")!=NULL)
			balance[nameid]+=n;
		else if(strstr(decrypt,"becomes")!=NULL)
			balance[nameid]=n;
		else if(strstr(decrypt,"spends")!=NULL && balance[nameid]>=n)
			balance[nameid]-=n;
		else if (strstr(decrypt,"gives")!=NULL && balance[nameid]>=n){
			balance[nameid]-=n;
			balance[anothernameid]+=n;
		}
	}
	for(int i=0;i<N;i++){
		printf("%s %d\n",user[i],balance[i]);
	}
	return 0;
}
