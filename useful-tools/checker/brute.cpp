#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
 
bool check(long long n)
{
	int c = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0) c++;
		else if(n % i == 0 && c == 3) return 0;
		
	if(c == 3) return 1;
	else return 0;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		cout << (check(x) ? "YES\n" : "NO\n");
	}
}
