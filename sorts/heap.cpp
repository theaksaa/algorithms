#include <stdio.h>
#include <algorithm>
using namespace std;

// n*log(n)

void heapadd(int *x, int i)
{
    while (i && x[i] < x[(i - 1) / 2])
    {
        swap(x[i], x[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heap(int *x, int d )
{
    int k = x[0], i = 0;
    x[0] = x[d];

    while (2 * i + 2 < d)
        if (x[2 * i + 1] > x[2 * i + 2])
        {
            if (x[2 * i + 2] > x[i]) swap(k,  x[2 * i + 2]);
            swap(x[i], x[2 * i + 2]);
            i = 2 * i + 2;
        }
        else
        {
            if (x[2 * i + 1] > x[i]) swap(k, x[2 * i + 1]);
            swap(x[i], x[2 * i + 1]);
            i = 2 * i + 1;
        }

    if (d - 1 == 2 * i + 1 && x[2 * i + 1] < x[i]) swap(x[i], x[2 * i + 1]);
}

void heapsort(int *x, int n)
{
    for (int i = 0; i < n; i++) heapadd(x, i);
    for (int i = n - 1; i >= 0; i--) heap(x, i);
}

int main()
{
    int n;
    scanf("%d", &n);
    int x[n];

    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    heapsort(x, n);
    
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
}
