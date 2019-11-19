#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
 
bool prime(long long n)
{
	for(int i = 2; i <= (int)sqrt(n); i++)
		if(n % i == 0) return 0;
	return 1;
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
		long long int_num = (long long)sqrt(x);
		double dob_num = sqrt(x);
		if(dob_num - int_num <= 1e-9 && int_num != 1)
			cout << (prime(int_num) ? "YES\n" : "NO\n");
		else cout << "NO\n";
	}
}
