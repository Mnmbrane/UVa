#include <stdio.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int main()
{
    unsigned int N, B, H, W, minAmount, cost, avail;
    
    while(scanf("%u %u %u %u", &N, &B, &H, &W) != EOF)
    {
        minAmount = (0xffffffff);
        while(H--)
        {
            scanf("%u", &cost);
            for(int i = 0; i < W; i++)
            {
                scanf("%u", &avail);
                if(avail >= N)
                {
                    minAmount = min(minAmount, cost * N);
                }
            }
        }
        
        if(minAmount <= B)
        {
            printf("%u\n", minAmount);
        }
        else
        {
            printf("stay home\n");
        }
        
    }

    return 0;
}