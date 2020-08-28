#include <stdio.h>
 
int paper[129][129]={0};
int white=0, blue=0;
 
int count(int x_s, int x_f, int y_s, int y_f);
int main(void)
{
    int n, i, j;
 
    scanf(" %d", &n);
 
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            scanf(" %d", &paper[i][j]); //0=흰색 1=파란색
    }
 
    count(1, n, 1, n);
 
    printf("%d \n", white);
    printf("%d", blue);
 
    return 0;
}
int count(int x_s, int x_f, int y_s, int y_f)
{
    int i, j, a=0;
 
//  printf("x_s=%d  x_f=%d  y_s=%d  y_f=%d \n", x_s, x_f, y_s, y_f);
 
    for(i=y_s; i<=y_f; i++)
    {
        for(j=x_s; j<=x_f; j++)
        {
            if(paper[i][j]!=paper[y_s][x_s])
            {
                a=1;
                break;
            }
        }
        if(a==1)
            break;
    }
 
    if(a==0)
    {
        if(paper[y_s][x_s]==0)
            white++;
        else
            blue++;
 
        return 0;
    }
    else
    {
        count(x_s, (x_s+x_f)/2, y_s, (y_s+y_f)/2);
        count(((x_s+x_f)/2)+1, x_f, y_s, (y_s+y_f)/2);
        count(x_s, (x_s+x_f)/2, ((y_s+y_f)/2)+1, y_f);
        count(((x_s+x_f)/2)+1, x_f, ((y_s+y_f)/2+1), y_f);
    }
}
