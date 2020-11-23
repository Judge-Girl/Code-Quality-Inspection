#include <iostream>
#include <algorithm>
#define MAXNUM 1000000
using namespace std;

long long int dates[MAXNUM];
int main(void)
{
    int n;
	long long int year, month, day;
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> year >> month >> day;
    	dates[i] = year * 10000 + month * 100 + day;
	}

    sort(&dates[0], &dates[n]);
    
    for (int i = 0; i < n; i++){
        cout << dates[i] / 10000;
		dates[i] = dates[i] % 10000;
		cout << ' ' << dates[i] / 100 << ' ' << dates[i] % 100 << '\n';
    }
    return 0;
}
