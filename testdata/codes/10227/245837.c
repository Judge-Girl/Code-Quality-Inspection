#include <stdio.h>
#include <string.h>
#define LENGTH 100000
#define MAXSIZE 12500
void findint(char *str)
{
	int i = 0;
	long long x = 0;
	while (*str != '\0'){
		x = x << 8;
		x |= *str;
		str++;
		i++;
		if (i == 8){
			printf("%lld\n", x);
			i = 0;
			x = 0;
		}
	}
	if (i % 8 != 0)
		x = x << 8 * (8 - i);
	printf("%lld", x);
}
void findstr(long long p[MAXSIZE], int n, char *str)
{
	char print;
	int shift = 56;
	for (int i = 0; i < n; i++){
		while (shift != 0){
			print = (p[i] >> shift) & 255;
			if (print != 0){
				*str = print;
				shift -= 8;
				str++;
			} else {
				*str = '\0';
				return;
			}
		}
		*str = p[i] & 255;
		str++;
		shift = 56;
	}
	
}
int main()
{
	int type, n;
	char str[LENGTH];
	long long p[MAXSIZE];
	scanf("%d", &type);
	if (type == 0){
		scanf("%s", str);
		findint(str);
	}
	else{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &p[i]);
		findstr(p, n, str);
		printf("%s", str);
	}
	
	return 0;
 } 
