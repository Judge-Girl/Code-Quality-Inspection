#include <stdio.h>
#include <string.h>


char user[32][32], A[32] , v[32] , B[32];
int main(){
	int i , N , mon[32] , cmd = 0 , x , y , m;
	char e[10] = "earns" , s[10] = "spends" , g[10] = "gives" , b[10] = "becomes";
	scanf("%d" , &N);
	char *start , *split;
	for(i = 0 ;  i < N ; i++){
		scanf("%s" , user[i]);
		scanf("%d" , &mon[i]);
	}
	while(scanf("%s", A) != EOF){
		x = -1;
		for(i = 0 ; i < N ; i++){
			if(strcmp(user[i] , A) == 0) x = i;
		}
		if(x == -1) continue;
		cmd = 0;
		scanf("%s" , v);
		start = v;
		split = strstr(start , e);
		if(split == NULL){
			split = strstr(start , s);
				if(split == NULL){
					split = strstr(start , b);
					if(split == NULL){
						split = strstr(start , g);
						if(split == NULL) continue;
						else  cmd = 3;
					}
					else cmd = 4;
				}
				else cmd = 2;
		
		}
		else cmd = 1;
		
		
		if(cmd == 1){
			scanf("%d" , &m);
			mon[x] += m;
		
		}
		else if(cmd == 2){
			scanf("%d" , &m);
			if(m > mon[x]) continue;
			else mon[x] -= m;
		
		
		}
		else if(cmd == 4){
			scanf("%d" , &m);
			mon[x] = m;
	
		}
		else if(cmd == 3){
		
			y = -1;
			scanf("%s" , B);
			scanf("%d" , &m);
	
			for(i = 0 ; i < N ; i++){
				if(strcmp(user[i] , B) == 0) y = i;
			}
	
			if(y == -1) continue;
			else{
				if(m > mon[x]) continue;
				else{
					mon[x] -= m;
					mon[y] += m;
				}
			}

		}
		
		
	}
	for(i = 0 ; i < N ; i++){
		printf("%s %d\n" , user[i] , mon[i] );
	}
}
