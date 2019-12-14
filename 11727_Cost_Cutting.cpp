#include <stdio.h>

using namespace std;

typedef unsigned short uint16;

int main()
{
    uint16 T, f, s, t, ans, c=1;
    scanf("%hu", &T);
    while(T--)
    {
        scanf("%hu %hu %hu", &f, &s, &t);
        if((f > s && f < t) || (f < s && f > t))
            ans = f;
        else if((s > f && s < t) || (s < f && s > t))
            ans = s;
        else
            ans = t;
        
        printf("Case %d: %d\n", c++, ans);
    }
    return 0;
}

