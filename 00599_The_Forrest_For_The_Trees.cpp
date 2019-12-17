#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define MAX_LETTERS (26)

#define li(letter) (letter - 'A')

set<char> adjList[MAX_LETTERS];
int count[MAX_LETTERS], track[MAX_LETTERS];
vector<char> list;

void func(char letter, int trackNum)
{
    //printf("func(%c, %d)\n", letter, trackNum);
    if(track[li(letter)] != -1)
    {
        //printf("Tracked!\n");
        return;
    }
    else
    {
        count[trackNum]++;
        track[li(letter)] = trackNum;
        for(char i: list)
        {
            //printf("iter (%c)\n", i);
            if(track[li(i)] == -1 && i != letter && (adjList[li(letter)].find(i) != adjList[li(letter)].end()))
            {
                func(i, trackNum);
            }
        }
    }
}

int main()
{
    int t, trackNum, trees, acorn;
    char buf[200], l;
    scanf("%d\n", &t);

    while(t--)
    {
        memset(count, 0, sizeof(count));
        memset(track, -1, sizeof(track));
        trackNum = 0;
        trees = 0;
        acorn = 0;
        while(fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '*')
        {
            adjList[li(buf[1])].insert(buf[3]);
            adjList[li(buf[3])].insert(buf[1]);
            
        }
        while((l = getchar()) != '\n' && l != EOF)
        {
            if(l == ',')
                continue;
            list.push_back(l);
        }
        
        for(char i: list)
        {
            if(track[li(i)] == -1)
            {
                func(i, trackNum);
                trackNum++;
            }
            // else
            // {
            //     printf("track[%d] = %d\n", li(i), track[li(i)]);
            // }
        }
        
        for(int i = 0; i < MAX_LETTERS; i++)
        {
            if(count[i] > 1)
            {
                trees++;
            }
            else if(count[i] == 1)
            {
                acorn++;
            }
            adjList[i].clear();
        }
        // for(int i = 0; i < MAX_LETTERS; i++)
        // {
        //     printf("count[%d] = %d\n", i, count[i]);
        // }
        
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
        // fgets(buf, sizeof(buf), stdin);
        // printf("[%s]\n", buf);
        list.clear();
    }
    return 0;
}
