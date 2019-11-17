#include <bits/stdc++.h>
#define MAX_ARR_EL 100000

using namespace std;

// n*k where k is max element in array

int main()
{
	int n;
	scanf("%d", &n);
	int x[n];
	int counting[MAX_ARR_EL] = { };
	int max_el = INT_MIN;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		counting[x[i]]++;
		if(x[i] > max_el) max_el = x[i]; // optimization
	}
			
	for(int i = 0; i <= max_el; i++) 
		for(int j = 0; j < counting[i]; j++) printf("%d ", i);
}
