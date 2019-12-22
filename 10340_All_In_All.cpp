#include <stdio.h>


int main()
{
    char s[100000], t[100000];
    
    while(scanf("%s %s", &s, &t) != EOF)
    {
        //printf("[%s] [%s]", s, t);
        
        int i = 0, j = 0;
        while(t[i] != '\0')
        {
            if(s[j] == t[i])
            {
                j++;
                if(s[j] == '\0')
                    break;
            }
            i++;
        }
        printf("%s\n", s[j] == '\0' ? "Yes" : "No");
        
    }

    return 0;
}
