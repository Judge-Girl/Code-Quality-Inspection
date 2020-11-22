#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void){
	char word[10000];
	int i,j;
	while(scanf("%s",word)!=EOF){
		char word3[10000]={0};
	    scanf("%d%d",&i,&j);
	    int length=strlen(word);
	    int space_number=0;
	    int space_index[10000]={0};
	    for(int a=0;a<length;a++){
		    if(word[a]==97||word[a]==101||word[a]==105||word[a]==111||word[a]==117){
			    space_index[space_number]=a;
			    space_number++; 
		    }
	    }
	    if(i==0){
	    	for(int a=0;a<=space_index[0];a++){
	    		printf("%c",word[a]);
	    		word3[a]=1;
	    	}
	    	for(int a=space_index[0]+1;a<length;a++){
	    		printf("+");
	    	}
	    }else{
	    	for(int a=0;a<=space_index[i-1];a++){
	    		printf("+");
	    	}
	    	for(int a=space_index[i-1]+1;a<=space_index[i];a++){
	    		printf("%c",word[a]);
	    		word3[a]=1;
	    	}
	    	for(int a=space_index[i]+1;a<length;a++){
	    		printf("+");
	    	}

	    }
	    printf("\n");
	    if(j==0){
            for(int a=0;a<=space_index[0];a++){
	    		printf("%c",word[a]);
	    		word3[a]=1;
	    	}
	    	for(int a=space_index[0]+1;a<length;a++){
	    		printf("+");
	    	}
	    }else{
	    	for(int a=0;a<=space_index[j-1];a++){
	    		printf("+");
	    	}
	    	for(int a=space_index[j-1]+1;a<=space_index[j];a++){
	    		printf("%c",word[a]);
	    		word3[a]=1;
	    	}
	    	for(int a=space_index[j]+1;a<length;a++){
	    		printf("+");
	    	}
	    }
	    printf("\n");
	    for(int a=0;a<length;a++){
	    	if(word3[a]==1)printf("+");
	    	else printf("%c",word[a]);
	    }
	    printf("\n");
    }
}
