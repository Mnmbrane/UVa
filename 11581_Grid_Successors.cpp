/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <set>

using namespace std;

unsigned short f(unsigned short &g)
{
    unsigned short retVal = 0;
    retVal = (((g >> 7) + (g >> 5)) & 1) << 8;
    retVal += (((g >> 8) + (g >> 6) + (g >> 4)) & 1) << 7;
    retVal += (((g >> 7) + (g >> 3)) & 1) << 6;
    retVal += (((g >> 8) + (g >> 4) + (g >> 2)) & 1) << 5;
    retVal += (((g >> 7) + (g >> 5) + (g >> 3) + (g >> 1)) & 1) << 4;
    retVal += (((g >> 6) + (g >> 4) + (g)) & 1) << 3;
    retVal += (((g >> 5) + (g >> 1)) & 1) << 2;
    retVal += (((g >> 2) + (g >> 4) + (g)) & 1) << 1;
    retVal += (((g >> 3) + (g >> 1)) & 1);
    
    return retVal;
}
int main()
{
    int n, i;
    unsigned short g, j;
    set<unsigned short> fg;
    scanf("%d", &n);
    
    while(n--)
    {
        g = 0;
        for(i = 0; i < 3; i++)
        {
            scanf("%hu", &j);
            //printf("%hu\n", j);
            switch(j)
            {
                case 0:
                    g = g << 3;
                    break;
                case 1:
                    g = (g << 3) | 1;
                    break;
                case 10:
                    g = (g << 3) | 2;
                    break;
                case 011:
                    g = (g << 3) | 3;
                    break;
                case 100:
                    g = (g << 3) | 4;
                    break;
                case 101:
                    g = (g << 3) | 5;
                    break;
                case 110:
                    g = (g << 3) | 6;
                    break;
                case 111:
                    g = (g << 3) | 7;
                    break;
                default:
                    //printf("default case %hu\n", g);
                    break;
            }
        }
        //printf("%hu\n", g);
        if(g == 0)
        {
            printf("-1\n");
        }
        else
        {
            fg.insert(g);
            i = 0;
            do
            {
                g = f(g);
                if(!g)
                {
                    printf("%d\n", i);
                    break;
                }
                else if(!fg.insert(g).second)
                {
                    printf("-1\n");
                    break;
                }
                i++;
            } while(true);
            fg.clear();
        }
    }

    return 0;
}

