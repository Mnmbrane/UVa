#include <stdio.h>
#include <string.h>

int main()
{
    double val, owed, dpayment, pay, dep[101], dep1;
    int dur, rec, i;
    
    while(scanf("%d %lf %lf %d", &dur, &dpayment, &owed, &rec) != EOF && dur > 0)
    {
        val = owed + dpayment;
        memset(dep, 0, sizeof(dep));
        while(rec--)
        {
            scanf("%d", &i);
            scanf("%lf", &dep[i]);
        }
        //owed = owed - dpayment;
        pay = owed / (dur * 1.0);
        for(i = 0; i <= dur; i++)
        {
            if(dep[i])
            {
                dep1 = dep[i];
            }
            val = val - (val * dep1);
            //printf("Val: %lf Owed: %lf pay: %lf\n", val, owed, pay);
            if(owed <= val)
            {
                printf("%d %s\n", i, (i > 1 || i == 0) ? "months" : "month");
                break;
            }
            owed = owed - pay;
        }
        
    }

    return 0;
}
