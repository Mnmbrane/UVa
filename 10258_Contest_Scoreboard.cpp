#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

typedef struct
{
    int contNum;
    set<int> prob;
    int penalty;
    int addedP[10];
} Contestant;

bool sortContestant(Contestant c1, Contestant c2)
{
    bool retVal = true;
    //printf("comparing %d and %d\n", c1.contNum, c2.contNum);
    
    if(c1.contNum == 0)
    {
        //printf("c1.contNum == 0\n");
        retVal = false;
    }
    else if(c2.contNum == 0 && c1.contNum > 0)
    {
        retVal = true;
    }
    else if(c1.prob.size() <= c2.prob.size())
    {
        if(c1.prob.size() == c2.prob.size())
        {
            if(c1.penalty >= c2.penalty)
            {
                if(c1.penalty == c2.penalty)
                {
                    if(c1.contNum > c2.contNum)
                    {
                        retVal = false;
                    }
                }
                else
                {
                    retVal = false;
                }
            }
        }
        else
        {
            retVal = false;
        }
    }
    
    //printf("Result = %s\n", retVal ? "TRUE": "FALSE");
    return retVal;
}


int main()
{
    int t, contNum, prob, penalty, i;
    char l;
    char buff[100];
    Contestant c[101];
    
    int contestantSize = sizeof(c) / sizeof(Contestant);
    while(scanf("%d", &t) != EOF)
    {
        getchar();
        getchar();
        while(t--)
        {
            for(i = 0; i < contestantSize; i++)
            {
                c[i].contNum = 0;
                c[i].prob.clear();
                memset(c[i].addedP, 0, sizeof(c[i].addedP));
                c[i].penalty = 0;
                c[i].contNum = 0;
                
            }
            while(fgets(buff, sizeof(buff), stdin) != NULL && strlen(buff) > 1)
            {
                sscanf(buff, "%d %d %d %c", &contNum, &prob, &penalty, &l);
                
                
                if(c[contNum].contNum == 0)
                {
                    c[contNum].contNum = contNum;
                    //printf("[%d]\n", contNum);
                }
                
                if(l == 'C')
                {
                    if(c[contNum].prob.insert(prob).second == true)
                    {
                        c[contNum].penalty += penalty;
                        c[contNum].penalty += c[contNum].addedP[prob];
                    }
                }
                else if(l == 'I')
                {
                    c[contNum].addedP[prob] += 20;
                }
            }
    
            stable_sort(c, c+contestantSize, sortContestant);
            
            i = 0;
            while(c[i].contNum != 0)
            {
                printf("%d %lu %d\n", c[i].contNum, c[i].prob.size(), c[i].penalty);
                
                i++;
            }
            // for(i = 0; i < contestantSize; i++)
            // {
            //     printf("%d %d %d\n", c[i].contNum, c[i].prob, c[i].penalty);
            // }
            
            if(t)
                printf("\n");
        }
    }

    return 0;
}

