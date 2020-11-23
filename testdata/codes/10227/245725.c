#include <stdio.h>
#include <string.h>
void findint(char str[100000])
{
	int l = strlen(str);
	int i = 0;
	long long x = 0;
	while (i != l){
		x = x << 8;
		x |= str[i];
		i++;
	//	printf("%llu\n", x);
		if (i % 8  == 0){
			printf("%lld\n", x);
			x = 0;
		}
	}
	while (i % 8 != 0){
		x = x << 8;
		i++;
	}
	printf("%lld", x);

}
void findstr(long long p[12500], int n, char str[100000])
{
	char print;
	int shift = 56, c = 0, test = 1;
	for (int i = 0; i < n; i++){
		while (shift != 0){
			print = (p[i] >> shift) & 255;
			if (print != 0){
				str[c] = print;
				shift -= 8;
				c++;
			} else test = 0;
			if (test == 0)
				break;
		}
		if (test == 0)
			break;
		str[c] = p[i] & 255;
		c++;
		shift = 56;
	}
	str[c] = '\0';
	printf("%s", str);
	
	
	
}
int main()
{
	int type, n;
	char str[100000];
	long long p[12500];
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
	}
	
	
	
	
	return 0;
 } 
