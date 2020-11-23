#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int y,m,d;
}pair;
int compare( pair* pa, pair* pb){
	if(pa->y<pb->y) return -1;
	else if(pa->y==pb->y&&pa->m<pb->m) return -1;
	else if(pa->y==pb->y&&pa->m==pb->m&&pa->d<pb->d) return -1;
	return 1;
}
pair arr[1000005];
int main(){
	int num,y,m,d;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d%d%d",&arr[i].y,&arr[i].m,&arr[i].d);
	}
	qsort(arr,num,sizeof(pair),compare);
	for(int i=0;i<num;i++){
		printf("%d %d %d\n",arr[i].y,arr[i].m,arr[i].d);	
	}

} 
