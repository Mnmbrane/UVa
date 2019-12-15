#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int uint32;

typedef pair<uint32, uint32> pii;

struct Comp
{
    bool operator()(const pii& p1, const pii& p2)
    {
        if(p1.second != p2.second)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

int main()
{
    priority_queue<pii, vector<pii>, Comp> q;
    uint32 id, t, k;
    char regStr[10] = { 0 };
    uint32 timeArr[3001] = { 0 };
    
    while(getchar() != '#')
    {
        scanf("%s %u %u\n", regStr, &id, &t);
        q.push(make_pair(id, t));
        timeArr[id] = t;
    }
    
    scanf("%u\n", &k);
    while(k--)
    {
        id = q.top().first;
        t = q.top().second;
        printf("%u\n", id);
        q.pop();
        
        q.push(make_pair(id, t + timeArr[id]));
    }
    
    return 0;
}