#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int graph[128][128], n, edge_n[128];
bool filled[128];

int search_clique(int indx, int *buff, int buff_size, int depth){
	int max=0, tn;
	if(!depth){
		int t_buff[128], t_buff_size=0;
		for(int i=0; i<buff_size; i++)
			if(graph[indx][*(buff+i)])
				t_buff[t_buff_size++]=*(buff+i);
		if(!t_buff_size)
			return 0;
		return search_clique(t_buff[0], t_buff+1, t_buff_size-1, 1)+1;
	}else{
		int t_buff[128], t_buff_size=0;
		for(int i=0; i<buff_size; i++)
			if(graph[indx][*(buff+i)])
				t_buff[t_buff_size++]=*(buff+i);
		if(!t_buff_size)
			return 0;
		if(t_buff_size==buff_size&&edge_n[indx]==(depth+t_buff_size))
			filled[indx]=1;
		for(int i=0; i<t_buff_size; i++){
			if(filled[*(t_buff+i)])
				continue;
			tn=search_clique(*(t_buff+i), t_buff+i+1, t_buff_size-i-1, depth+1);
			if(tn>max)
				max=tn;
		}
	}
	return max+1;
}

int main(){
	while(~scanf("%d", &n)){
		memset(edge_n, 0, n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				scanf("%d", &graph[i][j]);
				if(graph[i][j])
					edge_n[i]++, edge_n[j]++;
			}
		for(int i=0; i<n; i++)
			edge_n[i]/=2;
		int an=0, tn, buff[128], buff_size=0;
		for(int i=0; i<n; i++)
			buff[buff_size++]=i, filled[i]=0;
		for(int i=0; i<n; i++){
			if(filled[*(buff+i)])
				continue;
			tn=search_clique(i, buff, buff_size, 0)+1;
			if(tn>an)
				an=tn;
		}
		printf("%d\n", an);
	}
}

