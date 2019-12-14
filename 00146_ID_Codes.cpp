#include <stdio.h>
#include <algorithm>    // std::next_permutation, std::sort
#include <string.h>
using namespace std;

int main()
{
    char code[100];
    bool hasSuccessor;
    
    while(scanf("%s", &code) != EOF && code[0] != '#')
    {
        hasSuccessor = next_permutation(code, code+strlen(code));
        printf("%s\n", hasSuccessor ? code : "No Successor");
    }

    return 0;
}
