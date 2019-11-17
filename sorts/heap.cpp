#include <stdio.h>
#include <algorithm>

void heapadd(int *x, int i)
{
    while ( i && x[i] < x[ (i - 1) / 2 ] )
    {
        std::swap( x[i], x[ (i - 1 ) / 2 ] );
        i = ( i - 1 ) / 2;
    }
}

void heap(int *x, int d )
{
    int k = x[ 0 ], i = 0;
    x[ 0 ] = x[ d ];

    while ( 2 * i + 2 < d )
        if ( x[ 2 * i + 1 ] > x[ 2 * i + 2 ] )
        {
            if ( x[ 2 * i + 2 ] > x[ i ] ) std::swap( k,  x[ 2 * i + 2 ] );
            std::swap( x[ i ], x[ 2 * i + 2 ] );
            i = 2 * i + 2;
        }
        else
        {
            if ( x[ 2 * i + 1 ] > x[ i ] ) std::swap( k, x[ 2 * i + 1 ] );
            std::swap( x[ i ], x[ 2 * i + 1 ] );
            i = 2 * i + 1;
        }

    if ( d - 1 == 2 * i + 1 && x[ 2 * i + 1 ] < x[ i ] ) std::swap( x[ i ], x[ 2 * i + 1 ] );
}

void heapsort(int *x, int n)
{
    for ( int i = 0; i < n; i++ ) heapadd( x, i );
    
    for ( int i = n - 1; i >= 0; i -- ) heap( x, i );
}

int main()
{
    FILE *fin = fopen("in.in", "r");
    FILE *fout = fopen("out.out", "w");
        
    int n;
    fscanf(fin, "%d", &n);
    int x[n];

    for ( int i = 0; i < n; i++ ) fscanf(fin, "%d", &x[i]);
    heapsort( x, n );
    
    for ( int i = 0; i < n; i++ ) printf("%d ", x[i]);
    printf("\n");
}
