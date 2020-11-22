#include <stdio.h>
#include <stdlib.h>
#define N 50000
typedef struct{
	int x;	
	int y;
}Steph;

typedef struct{
	int x;
	int y;
}Shiro;

int dis(Steph steph, Shiro shiro){
	return abs(steph.x - shiro.x) + abs(steph.y - shiro.y);
}

int main(){
	Steph steph[N];
	Shiro shiro[N];
	int n, min_dis, tmp_dis;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		min_dis = 65536;
		scanf("%d%d", &steph[i].x, &steph[i].y);
		for (int j = 0; j < i; j++){
			tmp_dis = dis(steph[i], shiro[j]);
			if (tmp_dis < min_dis) min_dis = tmp_dis;
		}
		if (i != 0) printf("%d\n", min_dis);
		min_dis = 65536;
		scanf("%d%d", &shiro[i].x, &shiro[i].y);	
		for (int j = 0; j <= i; j++){
			tmp_dis = dis(steph[j], shiro[i]);
			if (min_dis > tmp_dis) min_dis = tmp_dis;
		}
		printf("%d\n", min_dis);
	}
}

