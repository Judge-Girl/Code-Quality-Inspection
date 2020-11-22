#include <stdio.h>
#include <string.h>
int main() {
	int type;
	scanf("%d", &type);
	if ( type == 0 ) {
		char S[100000];
		scanf("%s", S);
		int count = 0;
		int l = strlen(S);
		for ( int j = 0 ; j <= l/8 ; j++ ) {
			unsigned long long int uns = 0;
			for ( int i = 0 ; i < 8 ; i++ ) {
				uns <<= 8;
				if ( S[count] != '\0' ) {
					uns += S[count];
				}
				count++;
			}
			printf("%llu\n", uns);
		}
	} else if ( type == 1 ) {
		int n;
		scanf("%d", &n);
		unsigned long long int two_56 = 1;
		for ( int i = 0 ; i < 56 ; i++ ) {
			two_56 *= 2;
		}
		unsigned long long int uns;
		for ( int i = 0 ; i < n ; i++ ) {
			scanf("%llu", &uns);
			for ( int j = 0 ; j < 8 ; j++ ) {
				char c;
				c = uns / two_56;
				uns <<= 8;
				if ( c != 0 ) {
					printf("%c", c);
				}
			}
		}
		printf("\n");
	}
}
