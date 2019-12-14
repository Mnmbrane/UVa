#include <stdio.h>
typedef unsigned int uint32;

int main()
{
    uint32 mask, a, b, n, toggle;
    
    while(scanf("%u", &n) != EOF && n != 0)
    {
        mask = 1;
        toggle = 0;
        a = 0;
        b = 0;
        while(mask <= n)
        {
            if(n & mask)
                if(toggle)
                {
                    b |= (n & mask);
                    toggle = 0;
                }
                else
                {
                    a |= (n & mask);
                    toggle = 1;
                }
            //printf("%u %u\n", a, b);
            mask <<= 1;
        }
        
        printf("%u %u\n", a, b);
    }
    return 0;
}