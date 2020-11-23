#include<stdio.h>
#include<stdlib.h>



int main(void){
	int pos[100000][2];
	int N;
	scanf("%d",&N);
	for(int i = 0; i<2*N; i++){
		scanf("%d%d",&pos[i][0],&pos[i][1]);
		int min_dis = 2147483647;;
		if(i >= 1){
			if(i % 2 == 0){
				for(int j = 0; j<i; j++){
					if(j % 2 == 1){
						if(abs(pos[i][0]-pos[j][0]) + abs(pos[i][1] - pos[j][1]) < min_dis){
							min_dis = abs(pos[i][0]-pos[j][0]) + abs(pos[i][1] - pos[j][1]);
						}
					}
				}
				printf("%d\n",min_dis);
			}
			else{
				for(int j = 0; j<i; j++){
					if(j % 2 == 0){
						if(abs(pos[i][0]-pos[j][0]) + abs(pos[i][1] - pos[j][1]) < min_dis){
							min_dis = abs(pos[i][0]-pos[j][0]) + abs(pos[i][1] - pos[j][1]);
						}
					}
				}
				printf("%d\n",min_dis);
			}
		}
	}

	return 0;
}
