#include <stdio.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

int randomize(int a, int b)
{
	return rand() % (b - a + 1);
}

int main(int argc, char** argv)
{
	srand(*argv[1]);
	unordered_set<int> s;
	
	int n = randomize(2, 100);
	printf("%d\n", n);
	for(int i = 0; i < n; i++)
	{
		while(int x = randomize(2, 100))
		{
			if(s.find(x) == s.end())
			{
				printf("%d ", x);
				s.insert(x);
				break;
			}
		}
	}
	putchar('\n');
}
