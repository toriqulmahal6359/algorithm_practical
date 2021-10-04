#include <stdio.h>
#include <conio.h>
#include <math.h>

int m,n,x[10]= {0},g[10][10]= {0};

int main()
{
    int i,j;
    void mcolor();

    printf("No. of colors available: ");
    scanf("%d",&m);
    printf("No. of regions: ") ;
    scanf("%d",&n) ;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            printf("g[%d][%d] = ",i,j) ;
            scanf("%d",&g[i][j]) ;
        }
    mcolor();

    getch();
}

void mcolor()
{
    int i,k=1,backtrack(int),solution(int) ;
    void printsol() ;

    while(k!=0)
    {
        x[k]=(x[k]+1)%(m+1) ;
        printf("x[%d] = %d\n",k,x[k]) ;
        getch() ;
        if(x[k]!=0)
        {
            if(backtrack(k))
                continue ;
            if(solution(k))
            {
                printsol() ;
                return ;
            }
            else
                k++ ;
        }
        else
        {
            printf("%d colors are not sufficient\n",m) ;
            return ;
        }
    }
}

int backtrack(int k)
{
    int j;
    for(j=1; j<k; j++)
        if(g[j][k]==1 && x[j]==x[k])
        {
            return 1;
        }
    return 0;
}

int solution(int k)
{
    if(k==n)
        return 1 ;
    else
        return 0 ;
}

void printsol()
{
    printf("Solution is : ") ;
    for(int j=1; j<=n; j++)
        printf("%d ",x[j]);
    printf("\n");
}
