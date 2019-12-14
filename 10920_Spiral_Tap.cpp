#include <stdio.h>

using namespace std;

int main()
{
    int sz, p, i, min, max, row, col, j, k;
    
    
    while(scanf("%d %d", &sz, &p) != EOF && (sz | p))
    {
        min = 1;
        max = 3;
        i = 0;
        while((max * max) < p)
        {
            min = max;
            max += 2;
            i++;
        }
        row = col = (((sz + 1)/2) + i);
        printf("Row = %d Col = %d i = %d\n", row, col, i);
        
        j = sz > 1 ? (p - (min * min)) / (max - 1) : 0;
        k = sz > 1 ? (p - (min * min)) % (max - 1) : 0;
        
        printf("j = %d k = %d\n", j, k);
        
        if(j & k)
            switch(j)
            {
                case 0:
                    row++;
                    col-=(k-1);
                    break;
                case 1:
                    row -= (k-1);
                    col -= min;
                    break;
                case 2:
                    row -= min;
                    col = (col - min) + k;
                    break;
                case 3:
                    row = (row - min) + k;
                    col++;
                    break;
                default: 
                    break;
            }
        
        printf("Line = %d, column = %d.\n", row, col);
    }

    return 0;
}
