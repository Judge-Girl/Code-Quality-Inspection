#include <stdio.h>
#include <string.h>
char names[32][32];
int money[32];
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%s",names[i]);
		scanf("%d",&money[i]);
	}
	char name[32],ins[32],much[32],name2[32];
	while(scanf("%s",name)!=EOF){
		scanf("%s",ins);
		if(strstr(ins,"earns")!=NULL){
			int num;int flag=0;int namenum;
			scanf("%d",&num);
			for(i=0;i<n;i++){
			    if(strcmp(names[i],name)==0){
			    	namenum=i;
				    flag=1;
				    break;
			    }
		    }
		    if(flag==0) continue;
		    else{
		    	money[namenum]+=num;
		    }
		}
		else if(strstr(ins,"spends")!=NULL){
			int num;int flag=0;int namenum;
			scanf("%d",&num);
			for(i=0;i<n;i++){
			    if(strcmp(names[i],name)==0){
			    	namenum=i;
				    flag=1;
				    break;
			    }
		    }
		    if(flag==0) continue;
		    else{
		    	if(money[namenum]-num>=0)
		    	money[namenum]-=num;
		    }
		}
		else if(strstr(ins,"gives")!=NULL){
			int num;int flag=0;int namenum,namenum2;
			scanf("%s",name2);
			scanf("%d",&num);
			for(i=0;i<n;i++){
			    if(strcmp(names[i],name)==0){
			    	namenum=i;
				    flag=1;
				    break;
			    }
		    }
		    if(flag==0) continue;
		    for(i=0;i<n;i++){
			    if(strcmp(names[i],name2)==0){
			    	namenum2=i;
				    flag=2;
				    break;
			    }
		    }
		    if(flag==1) continue;
		    else{
		    	if(money[namenum]-num>=0){
		    		money[namenum]-=num;
		    		money[namenum2]+=num;
		    	}
		    }

		}
		else if(strstr(ins,"becomes")!=NULL){
			int num;int flag=0;int namenum;
			scanf("%d",&num);
			for(i=0;i<n;i++){
			    if(strcmp(names[i],name)==0){
			    	namenum=i;
				    flag=1;
				    break;
			    }
		    }
		    if(flag==0) continue;
		    else{
		    	if(num>=0){
		    		money[namenum]=num;
		    	}
		    }
		}
		else{
			char c;
			while(1){
				scanf("%c",&c);
				if(c=='\n') break;
			}
		}
	}
	for(i=0;i<n;i++) printf("%s %d\n",names[i],money[i]);
	return 0;
}

