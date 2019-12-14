#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
    bool t[1000000], conflict;
    int start, end, rep, n, m;
    
    while(scanf("%d %d", &n, &m) != EOF && (n | m))
    {
        conflict = false;
        memset(t, 0, sizeof(t));
        while(n && !conflict)
        {
            scanf("%d %d", &start, &end);
            
            bool comp[end-start] = { 0 };
            
            if(memcmp(&t[start], comp, end-start) == 0)
            {
                memset(&t[start], 1, end-start);
            }
            else
            {
                conflict = true;
            }
            n--;
        }
        
        while(m && !conflict)
        {
            scanf("%d %d %d", &start, &end, &rep);
            
            bool comp[end-start] = { 0 };
            
            while(end < sizeof(t) && !conflict)
            {
                if(memcmp(&t[start], comp, end-start) == 0)
                {
                    memset(&t[start], 1, end-start);
                }
                else
                {
                    conflict = true;
                }
                start += rep;
                end += rep;
            }
            
            if(start < sizeof(t) && !conflict)
            {
                bool comp2[sizeof(t) - start] = { 0 };
                if(memcmp(&t[start], comp2, sizeof(t) - start) == 0)
                {
                    memset(&t[start], 1, sizeof(t) - start);
                }
                else
                {
                    conflict = true;
                }
            }
            
            m--;
        }
        
        while(n)
        {
            scanf("%d %d", &start, &end);
            n--;
        }
        
        while(m)
        {
            scanf("%d %d %d", &start, &end, &rep);
            m--;
        }
        
        printf("%s\n", conflict ? "CONFLICT" : "NO CONFLICT");
    }
    //printf("%d\n", memcmp());

    return 0;
}