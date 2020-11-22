#include <stdio.h>

int main(int argc, char const *argv[])
{
	char str[3][10003], all[] = {'a', 'e', 'i', 'o', 'u'};
	int mom[2], change = 0, i, j, k, m_i, start_end[2][2];

	while( scanf("%s%d%d", str[2], &mom[0], &mom[1]) == 3 ){
		change = 0;
		if (mom[0] > mom[1]){
			i = mom[0];
			mom[0] = mom[1];
			mom[1] = i;
			change = 1;
		}
		m_i = -1;
		k = -1;
		for(i = 0; str[2][i] != '\0'; i++){
			for(j = 0; j < 5; j++){
				if(str[2][i] == all[j]){
					m_i++;
					if(m_i == mom[0]){
						start_end[0][1] = i;
						start_end[0][0] = k+1;
						if(k+1 > i)
							start_end[0][0] = i;
					}
					if(m_i == mom[1]){
						start_end[1][1] = i;
						start_end[1][0] = k+1;
						if(k+1 > i)
							start_end[1][0] = i;
					}
					k = i;
					break;
				}
			}
			if(m_i >= mom[1])
				break;
		}
		if(!change){
			for(j = 0; j < 2; j++){
				for(i = 0; str[2][i] != '\0'; i++){
					if(i < start_end[j][0])
						str[j][i] = '+';
					else if (i > start_end[j][1])
						str[j][i] = '+';
					else
						str[j][i] = str[2][i];
				}			
			}
		}
		else{
			for(j = 0; j < 2; j++){
				for(i = 0; str[2][i] != '\0'; i++){
					if(i < start_end[(j+1)%2][0])
						str[j][i] = '+';
					else if (i > start_end[(j+1)%2][1])
						str[j][i] = '+';
					else
						str[j][i] = str[2][i];
				}			
			}
		}
		for(i = 0; str[2][i] != '\0'; i++){
			if(i >= start_end[0][0] && i <= start_end[0][1])
				str[2][i] = '+';
			else if (i >= start_end[1][0] && i <= start_end[1][1])
				str[2][i] = '+';
		}
	

		for(i = 0; i < 3; i++){
			for(j = 0; str[2][j] != '\0'; j++)
				printf("%c", str[i][j]);
			printf("\n");
		}
	}


	return 0;
}
