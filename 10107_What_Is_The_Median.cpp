#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main () {
    unsigned int d, size, b = 0, a = 0;
    multiset<unsigned int>::iterator medIt;
    multiset<unsigned int> x;

    scanf("%du", &d);
    x.insert(d);
    medIt = x.begin();
    printf("%d\n", *medIt);
    
    while(scanf("%d", &d) != EOF)
    {
        x.insert(d);
        if(d >= *medIt)
        {
            a++;
            if(b != 0)
            {
                b = 0;
                a = 0;
            }
            if(a == 2)
            {
                a = 0;
                medIt++;
            }
        }
        else if(d < *medIt)
        {
            b++;
            if(a != 0)
            {
                a = 0;
                b = 0;
            }
            else if(b == 2)
            {
                b = 0;
                medIt--;
            }
        }
        
        
        
        
        //printf("medit: %u\n", *medIt);
        //printf("next: %u\n", *next(medIt, 1));
        //printf("prev: %u\n", *prev(medIt, 1));
        if(a == 1)
        {
            printf("%u\n", (*medIt + *(next(medIt, 1))) / 2);
        }
        else if(b == 1)
        {
            printf("%u\n", (*medIt + *(prev(medIt, 1))) / 2);
        }
        else
        {
            printf("%u\n", *medIt);
        }
        //printf("medit after: %u\n", *medIt);
    }


    return 0;
}