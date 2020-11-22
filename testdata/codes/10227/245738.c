#include <stdio.h>
#include <string.h>

unsigned long long int integer_bits[12500] = {0};
unsigned long long int temp;
char input[100000];

int main(){
	int i,j;
	int type;
	int arr_size;

	scanf("%d",&type);

	if(type == 0){
		scanf("%s",input);
		int length = strlen(input);
		int curr_shift = 64;
		int count = 0;

		if(length >= 8){
			int count_word = 0;
			for(i=0;i<(length/8)+1;i++){
				curr_shift = 64;
				for(j=0;j<8;j++){
					if(input[count_word] == '\0'){
						curr_shift -= 8;
						temp = 0;
						integer_bits[count] |= temp;
					}
					else{
						curr_shift -= 8;
						temp = 0;
						temp |= input[count_word];
						temp = temp << curr_shift;
						integer_bits[count] |= temp;
					}
					count_word++;
				}
				count++;
			}
			for(i=0;i<count;i++){
				printf("%llu\n",integer_bits[i]);
			}

		}
		else{
			for(i=0;i<8;i++){
				curr_shift -= 8;
				temp = 0;
				temp |= input[i];
				temp = temp << curr_shift;
				integer_bits[count] |= temp;
			}
			printf("%llu\n",integer_bits[count]);
		}
	}
	else{
		scanf("%d",&arr_size);
		int curr_shift = 64;
		int count_word = 0;

		for(i=0;i<arr_size;i++){
			scanf("%llu",&integer_bits[i]);
			for(j=0;j<8;j++){
				curr_shift -= 8;
				temp = integer_bits[i] >> curr_shift;
				input[count_word] = temp;
				count_word++;
			}
		}
		printf("%s\n",input);

	}

	return 0;
}
