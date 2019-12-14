#include <stdio.h>
#include <set>
#include <vector>

using namespace std;
int main()
{
    multiset<int, greater<int>> sg;
    multiset<int, greater<int>> sb;
    vector<int> sg_add, sb_add;
    int b, t, sg_n, sb_n, i;
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &b, &sg_n, &sb_n);
        while(sg_n--)
        {
            scanf("%d", &i);
            sg.insert(i);
        }
        while(sb_n--)
        {
            scanf("%d", &i);
            sb.insert(i);
        }
        
        // while both sides have a lemming
        while(!sg.empty() && !sb.empty())
        {
            for(int i = 0; i < b; i++)
            {
                multiset<int, greater<int>>::iterator sg_l = (sg.begin());
                multiset<int, greater<int>>::iterator sb_l = (sb.begin());
                if(sg_l != sg.end() && sb_l != sb.end())
                {
                    if((*sg_l) > (*sb_l))
                    {
                        //printf("b = %d sg [%d] > sb[%d]\n", i, *sg_l, *sb_l);
                        sg_add.push_back(*sg_l - *sb_l);
                    }
                    else if(*sb_l > *sg_l)
                    {
                        //printf("b = %d sb [%d] > sg[%d]\n", i, *sb_l, *sg_l);
                        sb_add.push_back(*sb_l - *sg_l);
                    }
                    sg.erase(sg_l);
                    sb.erase(sb_l);
                }
                else
                {
                    break;
                }
            }
            copy( sg_add.begin(), sg_add.end(), inserter( sg, sg.end() ) );
            copy( sb_add.begin(), sb_add.end(), inserter( sb, sb.end() ) );
            sg_add.clear();
            sb_add.clear();
        }
        
        if(!sg.empty())
        {
            printf("green wins\n");
            for(auto &e : sg)
            {
                printf("%d\n", e);
            }
        }
        else if(!sb.empty())
        {
            printf("blue wins\n");
            for(auto &e : sb)
            {
                printf("%d\n", e);
            }
        }
        else
        {
            printf("green and blue died\n");
        }
        sb.clear();
        sg.clear();
        if(t)
            printf("\n");
    }

    return 0;
}

