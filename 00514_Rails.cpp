#include <stdio.h>

struct Stack
{
    int top;
    int s[1001];
    
    Stack()
    {
        top = 0;
    }
    void push(int val)
    {
        s[top++] = val;
    }
    
    void iota_push(int min, int max)
    {
        for(int i = min; i <= max; i++)
        {
            push(i);
        }
    }
    int pop()
    {
        return --top > -1 ? s[top] : -1;
    }
    void reset()
    {
        top = 0;
    }
    
};

typedef struct Stack stack;

int main()
{
    int N, comp, min;
    bool ans;
    
    stack s;
    
    while(scanf("%d", &N) != EOF && N != 0)
    {
        while(true)
        {
            min = 0;
            comp = -1;
            ans = true;
            s.reset();
            
            for(int i = 0; i < N && comp != 0; i++)
            {
                scanf("%d", &comp);
                if(comp > min)
                {
                    s.iota_push(min+1, comp);
                    min = comp;
                }
                
                if(comp != s.pop())
                {
                    ans = false;
                }
                
            }
            
            if(comp == 0)
                break;
            else
                printf("%s\n", ans ? "Yes" : "No");
        }
        
        printf("\n");
    }

    return 0;
}