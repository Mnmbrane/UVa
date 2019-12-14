#include <stdio.h>
#include <string.h>
#include <set>
#include <utility>
#include <functional>

#define SIZE (1000000)
using namespace std;
int main()
{
    int t;
    scanf("%d\n", &t);
    
    string species;
    char buff[100];
    int countArr[SIZE];
    hash<string> countHash;
    int count;
    set<string> speciesSet;
    
    while(t--)
    {
        count = 0;
        while(fgets(buff, sizeof(buff), stdin) != nullptr)
        {
            int len = strlen(buff);
            if(len > 0 && buff[0] != '\n')
            {
                if(buff[len - 1] == '\n')
                    buff[len - 1] = '\0';
                species = buff;
                countArr[countHash(species) % SIZE]++;
                speciesSet.insert(species);
                count++;
            }
            else
                break;
            
        }
        
        for (set<string>::iterator it = speciesSet.begin(); it != speciesSet.end(); ++it)
            printf("%s %.4f\n", (*it).c_str());
        if(t)
            printf("\n");
    }
    
    return 0;
}