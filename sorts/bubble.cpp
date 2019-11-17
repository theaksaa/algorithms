#include <stdio.h>
#include <algorithm>
using namespace std;

// n^2

int main()
{
	int n;
	scanf("%d", &n);
	int x[n];
	
	for(int i = 0; i < n; i++) scanf("%d", &x[i]);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1; j++)
			if(x[j] > x[j + 1]) swap(x[j], x[j + 1]);
			
	for(int i = 0; i < n; i++) printf("%d ", x[i]);
}
