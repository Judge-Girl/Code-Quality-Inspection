#include <stdio.h>
#include <math.h>
#define MAXSTRLEN 100000
#define MAXVALUENUMBER 12500 
void print_one(int count_i,long long int value[100000],int count_element)
{
		int zero = 0;
		if(count_i % 8 == 0){
			zero = 1;
		}
		while(count_i % 8 != 0){
			value[count_element] = value[count_element] << 8;
			count_i++;
		}
		for(int k = 0; value[k] != -1;k++){
			printf("%lld\n",value[k]);
		}
		if(zero == 1){
			printf("0");
		}
}
void one_plus(char string[MAXSTRLEN],long long int value[100000])
{
		int count_element = 0;
		int count_i;
		int flag = 1;
		for(int i = 0; string[i] != '\0';i++){
			if(i % 8 == 0 && flag == 0){
				count_element++;
				flag = 1;
			}
			flag = 0;
			value[count_element] = value[count_element] << 8;
			value[count_element] += string[i];
			count_i = i;
			//printf("count_i = %d value[%d] = %lld\n",count_i,count_element,value[count_element]);
		}
		count_i++;
		print_one(count_i,value,count_element);
}
void two(int number)
{
		long long int value[MAXVALUENUMBER];
		char result[MAXSTRLEN];
		int count_len = 0;
		for(int i = 0; i < number;i++){
			scanf("%lld",&value[i]);
			int count_8 = 1;
			long long int power;
			while(count_8 <= 8){
				power = pow(2,8);
				result[count_len] = ((value[i]>> (64- count_8 * 8)) % power);
				count_8++;
				count_len++;
			}
		}
		printf("%s",result);
}
int main(void)
{
	int type;
	scanf("%d",&type);
	if(type == 0){
		char string[MAXSTRLEN];
		scanf("%s",string);
		long long int value[100000];
		for(int i = 0; i < 100000;i++){
			value[i] = -1;
		}
		one_plus(string,value);
	}
	else{
		int number;
		scanf("%d",&number);
		two(number);
	}
}
