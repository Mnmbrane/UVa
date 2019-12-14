#include <stdio.h>

using namespace std;

#define LINE_MAX (100002)

struct Soldier_t
{
    unsigned int id;
    Soldier_t* left;
    Soldier_t* right;
};

typedef struct Soldier_t Soldier;

int main()
{
    Soldier s_list[LINE_MAX];
    int s, b, l, r;
    while(scanf("%d %d", &s, &b) != EOF && (s | b))
    {
        s_list[1].left = NULL;
        s_list[1].right = NULL;
        s_list[1].id = 1;
        for(int i = 2; i <= s; i++)
        {
            s_list[i].left = &s_list[i - 1];
            s_list[i].right = NULL;
            s_list[i - 1].right = &s_list[i];
            
            s_list[i].id = i;
        }
        
        int i = 1;
        
        while(b--)
        {
            scanf("%d %d", &l, &r);
            //printf("%d %d\n", l, r);
            if(s_list[l].left == NULL)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", s_list[l].left->id);
                s_list[l].left->right = s_list[r].right;
            }
            
            if(s_list[r].right == NULL)
            {
                printf("*\n");
            }
            else
            {
                printf("%d\n", s_list[r].right->id);
                s_list[r].right->left = s_list[l].left;
            }
            
            
        }
        printf("-\n");
    }

    return 0;
}