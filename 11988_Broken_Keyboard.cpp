#include <stdio.h>
#include <list>
#include <string.h>

using namespace std;

int main()
{
    char buf[100005];
    list<char*> l;
    int insert;
    while(fgets(buf, sizeof(buf), stdin) != NULL)
    {
        insert = 0;
        int bufSize = strlen(buf);
        if(buf[bufSize - 1] == '\n')
        {
            buf[bufSize - 1] = '\0';
        }
        
        for(int i = 0; i < bufSize; i++)
        {
            if(buf[i] == '[')
            {
                buf[i] = '\0';
                insert = 0;
                continue;
            }
            else if(buf[i] == ']')
            {
                buf[i] = '\0';
                insert = 1;
                continue;
            }
            
            if(insert == -1)
            {
                continue;
            }
            else if(insert == 0)
            {
                l.push_front(&buf[i]);
            }
            else
            {
                l.push_back(&buf[i]);
            }
            
            insert = -1;
        }
        while(!l.empty())
        {
            fputs(l.front(), stdout);
            l.pop_front();
        }
        printf("\n");
    }

    return 0;
}