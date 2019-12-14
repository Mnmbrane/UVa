#include <stdio.h>

int main()
{
   long long n, l, r;
   
   scanf("%lld", &n);
   while(n--)
   {
       scanf("%lld %lld", &l, &r);
       
       printf("%c\n", (l > r) ? '>' : ((l < r) ? '<' : '='));
   }

    return 0;
}

