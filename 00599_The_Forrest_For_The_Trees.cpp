#include <stdio.h>
#include <utility>
#include <map>
#include <numeric>

using namespace std;

#define MAX_LETTERS (26)

#define li(letter) (letter - 'A')
typedef unsigned char uint8;
typedef pair<uint8, uint8> uu;
uint8 alph[MAX_LETTERS];

uint8 findRoot(char letter, uint8& weight)
{
    uint8 root = li(letter);
    while(root != alph[li(letter)])
    {
        root = alph[li(letter)];
        letter = 'A' + alph[li(letter)];
        weight++;
    }
    return root;
}

int main()
{
    int t, trees, acorn;
    map<uint8, uint8> count;
    pair<map<uint8, uint8>::iterator, bool> ret;
    char c1, c2;
    uint8 w1, w2, r1, r2;
    scanf("%d\n", &t);

    while(t--)
    {
        iota(alph, alph+sizeof(alph), 0);
        
        trees = 0;
        acorn = 0;
        while(getchar() != '*')
        {
            w1 = 0;
            w2 = 0;
            c1 = getchar();
            getchar();
            c2 = getchar();
            getchar();
            getchar();
            
            r1 = findRoot(c1, w1);
            r2 = findRoot(c2, w2);
            
            if(w1 >= w2)
            {
                alph[r2] = alph[r1];
            }
            else
            {
                alph[r1] = alph[r2];
            }
        }
        
        // for(uint8 i = 0; i < MAX_LETTERS; i++)
        // {
        //     printf("%u ", alph[i]);
        // }
        // printf("\n");
        
        while(getchar() == '*');

        while((c1 = getchar()) != '\n' && c1 != EOF)
        {
            if(c1 == ',')
            {
                continue;
            }
            else
            {
                //printf("%c\n", c1);
                ret = count.insert(make_pair(findRoot(c1, w1), 1));
                if(!ret.second)
                {
                    (ret.first)->second++;
                }
            }
        }
        
        
        for (auto const& x : count)
        {
            if(x.second > 1)
            {
                trees++;
            }
            else
            {
                acorn++;
            }
        }
        
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
        
        count.clear();
    }
    return 0;
}