#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    int n, prev, curr, m;
    bool a[5000] = { 0 };
    bool jolly;
    while(scanf("%d", &n) != EOF)
    {
        jolly = true;
        scanf("%d", &prev);
        memset(a, true, n);
        while (--n)
        {
            scanf("%d", &curr);
            
            if(jolly)
            {
                m = abs(prev - curr);
                jolly = a[m];
                a[m] = 0;
                prev = curr;
            }
            
        }
        
        printf("%s\n", jolly ? "Jolly" : "Not Jolly");
    }

    return 0;
}