#include <stdio.h>
#include <string.h>
#define RMAX (1000)
#define CMAX (1000)

int main()
{
    int N, n;
    char big[RMAX][CMAX], small[RMAX][CMAX];
    bool match;
    
    int count[4];
    while(scanf("%d %d", &N, &n) != EOF && (N || n))
    {
        memset(count, 0, sizeof(count));
        for(int i = 0; i < N; i++)
        {
            scanf("%s", &big[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%s", &small[i]);
        }
        
        for(int i = 0; (i + n - 1) < N; i++)
        {
            for(int j = 0; (j + n - 1) < N; j++)
            {
                // 0
                match = true;
                for(int row = 0; row < n && match; row++)
                {
                    for(int col = 0; col < n && match; col++)
                    {
                        match = (big[i + row][j + col] == small[row][col]);
                    }
                }
                count[0] += match;
                
                // 90
                match = true;
                for(int col = 0, k = 0; col < n && match; col++, k++)
                {
                    for(int row = n - 1, l = 0; row >= 0 && match; row--, l++)
                    {
                        match = (big[i + k][j + l] == small[row][col]);
                    }
                }
                count[1] += match;
                // 180
                match = true;
                for(int row = n - 1, k = 0; row >= 0 && match; row--, k++)
                {
                    for(int col =  n - 1, l = 0; col >= 0 && match; col--, l++)
                    {
                        match = (big[i + k][j + l] == small[row][col]);
                    }
                }
                count[2] += match;
                
                // 270
                match = true;
                for(int col = n - 1, k = 0; col >= 0 && match; col--, k++)
                {
                    for(int row = 0, l = 0; row < n && match; row++, l++)
                    {
                        match = (big[i + k][j + l] == small[row][col]);
                    }
                }
                count[3] += match;
            }
        }
        
        printf("%d %d %d %d\n", count[0], count[1], count[2], count[3]);
    }

    return 0;
}