#include<stdio.h>
#include<stdlib.h>
int main (void)
{
	int n, a[50000], b[50000], c[50000], d[50000];
	long long s[50000];
	int count1, count2, i, k, temp;
	scanf("%d%d%d", &n, &a[0], &b[0]);
	count1 = 1;
	count2 = 0;
	for (i=1; i<2*n; i++)
	{
		if (i%2==0)
		{
			scanf("%d%d", &a[count1], &b[count1]);
			for (k=0; k<count1; k++)
			{
				s[k] = abs(a[count1]-c[k]) + abs(b[count1]-d[k]);
			}
			temp = 0;
			for (k=1; k<count1; k++)
			{
				if (s[k]<s[temp])
				{
					temp = k;
				}
			}
			printf("%lld\n", s[temp]);
			count1++;
		}
		else if (i%2==1)
		{
			scanf("%d%d", &c[count2], &d[count2]);
			for (k=0; k<=count2; k++)
			{
				s[k] = abs(c[count2]-a[k]) + abs(d[count2]-b[k]);
			}
			temp = 0;
			for (k=1; k<=count2; k++)
			{
				if (s[k]<s[temp])
				{
					temp = k;
				}
			}
			printf("%lld\n", s[temp]);
			count2++;
		}
	}
	return 0;
}
