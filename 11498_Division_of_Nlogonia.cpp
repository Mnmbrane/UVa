#include <stdio.h>

int main()
{
    int k, n, m, x, y;
    while(scanf("%d", &k) != EOF && k != 0)
    {
        scanf("%d %d", &n, &m);
        while(k--)
        {
            scanf("%d %d", &x, &y);
            x = x - n;
            y = y - m;
            
            if(x == 0 || y == 0)
            {
                printf("divisa\n");
            }
            else if(x > 0)
            {
                if(y > 0)
                {
                    printf("NE\n");
                }
                else
                {
                    printf("SE\n");
                }
            }
            else
            {
                if(y > 0)
                {
                    printf("NO\n");
                }
                else
                {
                    printf("SO\n");
                }
            }
        }
    }

    return 0;
}