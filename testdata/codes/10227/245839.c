#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int taskType;
	char str[100000];
	int arrSize;
	unsigned long long int arr[12499] = {0};

	scanf("%d", &taskType);

	//string to integer array
	if (taskType == 0) {
		scanf("%s", str);
		int strSize = strlen(str);
		//printf("length of string is %d\n", strSize);
		int arrCnt = -1;
		for (int i = 0; i < strSize+1; i++) {
			if (i % 8 == 0) {
				arrCnt++;
			}
			unsigned long long int tmp = str[i];
			tmp = tmp << (7 - (i % 8)) * 8;
			arr[arrCnt] |= tmp;
		}
		for (int i = 0; i < arrCnt + 1; i++) {
			printf("%lld\n", arr[i]);
		}

	} else if (taskType == 1) {
		scanf("%d", &arrSize);
		unsigned long long int num;
		char one = 255;
		int charCnt = 0;
		for (int i = 0; i < arrSize; i++) {
			unsigned long long int mask = one;
			scanf("%lld", &num);
			for (int j = 0; j < 8; j++) {
				unsigned long long int newMask = mask << (7 - j) * 8;
				char tmp = (num & newMask) >> (7 - j) * 8;
				str[charCnt] = tmp;
				charCnt++;
			}
		}
		printf("%s", str);

	}






	return 0;
}
