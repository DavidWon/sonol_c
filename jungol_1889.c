#incldue <stdio.h>
#include <stdlib.h>

void queens(int cnt);
int promising(int pos);
int n;
int col[255] = {0,};

int main()
{
    scanf("%d", &n);
    queens(0);
    return 0;
}

void queens(int i)
{
    int j;

    if (promising(i))
    {
        if (i == n)
        {

        }
        else
        {
            for (j = 1; j <= n; j++)
            {
                col[i+1] = j;
                queens(i+1);
            }
        }
    }
}

int promising(int i)
{
    int k = 1, promising = 1;
    while (k < i && promising)
    {
        if (col[i] == col[k] || abs(col[i]-col[k]) == abs(i-k))
            promising = 0;
        k++;
    }
    return promising;
}
