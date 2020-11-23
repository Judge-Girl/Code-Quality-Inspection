#include<stdio.h> 
#include<string.h>
#include<ctype.h>
int main()
{
	int i, j, find, count, index[10000], x, y;
	char string[10000], first[10000], second[10000];
	while(scanf("%s%d%d",&string,&i,&j) == 3){
		for(x = 0;x < 10000;x++){
			index[x] = -1;
			first[x] = '+';
			second[x] = '+';
		}
		first[strlen(string)] = '\0';
		second[strlen(string)] = '\0';
		count = 0;
		for(x = 0;x < strlen(string);x++){
			if(string[x] == 'a' || string[x] == 'e' || string[x] == 'i' || string[x] == 'o'||
			string[x] == 'u'){
				index[count] = x;
				count++;
			}
		}
		if(i == 0){
			strncpy(first,string,index[i] + 1);
			for(x = 0;x <= index[i];x++)
				string[x] = '+';
		}
		if(i != 0){
			strncpy(&first[index[i - 1] + 1],&string[index[i - 1] + 1],index[i] - index[i - 1]);
			for(x = index[i - 1] + 1;x <= index[i];x++)
				string[x] = '+';
		}
		if(j == 0){
			strncpy(second,string,index[j] + 1);
			for(x = 0;x <= index[j];x++)
				string[x] = '+';
		}
		if(j != 0){
			strncpy(&second[index[j - 1] + 1],&string[index[j - 1] + 1],index[j] - index[j - 1]);
			for(x = index[j - 1] + 1;x <= index[j];x++)
				string[x] = '+';
		}
		printf("%s\n%s\n%s\n",first,second,string);
	}
}

