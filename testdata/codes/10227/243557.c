#include<stdio.h>
#include<string.h>
#define ll long long
#define BYTE 8

char s[100005];
int main() {
	int t;
	scanf("%d", &t);
	if(t==0) {
		scanf("%s", s);
		ll o=0;
		int l=strlen(s);
		int i;
		for(i=0;i<=l;i++) {
			o |= (ll)(s[i]) << BYTE*(7-(i%8));
			if(i%8==7) {
				printf("%lld\n", o);
				o=0;
			}
		} 
		if(i%8)printf("%lld\n", o);
	}
	else {
		int n;
		scanf("%d", &n);
		int i,j,q=0;
		ll x;
		for(i=0;i<n;i++) {
			scanf("%lld", &x);
			for(j=0;j<8;j++) {
				s[q++] = (char)(x>>((7-j)*BYTE));
			}
		}
		printf("%s\n", s);
	}
				
	return 0;
}

