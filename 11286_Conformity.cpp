#include <stdio.h>
#include <array>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    short n;
    array<short, 5> classes;
    map<array<short, 5>, int> frequency;
    int max, freqCount;
    
    while(scanf("%hd", &n) != EOF && n != 0)
    {
        max = 0;
        while(n--)
        {
            scanf("%hd %hd %hd %hd %hd", 
                &(classes[0]), &(classes[1]), &(classes[2]), &(classes[3]), &(classes[4]));
            sort(classes.begin(), classes.end());
            frequency.insert(make_pair(classes, 0));
            freqCount = ++frequency[classes];
            max = max < freqCount ? freqCount : max;
        }
        freqCount = 0;
        for(auto &e : frequency)
        {
            if(max == e.second)
            {
                freqCount += max;
            }
        }
        printf("%d\n", freqCount);
        frequency.clear();
    }
    
    return 0;
}
