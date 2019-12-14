#include <stdio.h>
#include <string.h>

typedef unsigned uint;
#define bool char
#define true (1)
#define false (0)
#define SIZE (2000000)
#define fastscan(x)\
{\
    x = 0;\
    c=getchar();\
    for(;(c>47 && c<58);c=getchar())\
     x = (x<<1) + (x<<3) +c -48;\
}


int main()
{
    uint count;
    static bool hash[SIZE] = { 0 };
    static uint list[SIZE] = { 0 };
    char buf[8] = { 0 };
    register uint c, m, n, i, j;
    
    fastscan(m);
    fastscan(n);
    while(m | n)
    {
        count = j = 0;
        while(m)
        {
            --m;
            fastscan(i);
            list[j++] = i;
            hash[i] = true;
        }
        while(n)
        {
            --n;
            fastscan(i);
            count += hash[i];
        }
        i=0;
        if(count)
        {
            while(count)
            {
                buf[i++] = (count % 10) + '0';
                count /= 10;
            }
            while(i)
            {
                --i;
                putchar(buf[i]); 
            }
        }
        else
        {
            putchar('0');
        }
        memset(buf, 0, sizeof(buf));
        putchar('\n');
        
        i = j;
        while(i)
        {
            --i;
            hash[list[i]] = 0;
        }
        memset(list, 0, j);
        
        fastscan(m);
        fastscan(n);
    }
    return 0;
}

