#include <stdio.h>
#include <string.h>

using namespace std;

#define fastscan(x)\
{\
    x = 0;\
    c=getchar();\
    for(;(c>47 && c<58);c=getchar())\
     x = (x<<1) + (x<<3) +c -48;\
}

int main()
{
    int n, k, m, newlines;
    register unsigned char ch, c;
    unsigned long long paidChars[256];
    unsigned long long accum;
    fastscan(n);
    while(n--)
    {
        memset(paidChars, 0, sizeof(paidChars));
        accum = 0;
        fastscan(k);
        while(k--)
        {
            ch = getchar();
            getchar();
            fastscan(paidChars[ch]);
            
        }
        
        fastscan(m);
        newlines = 0;
        do
        {
            ch = getchar();
            newlines += (ch == '\n');
            accum += paidChars[ch];
        } while(newlines < m);
        printf("%.2lf$\n", (accum/100.0));
    }

    return 0;
}