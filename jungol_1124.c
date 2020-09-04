#include <stdio.h>

int p[101][101] = {0};

int main()
{
  int n;
  int x, y;
  int i, j;

  scanf("%d", &n);

  while (n > 0)
  {
    scanf("%d %d", &x, &y);
    for (i = x; i < x +10; ++i)
    {
      for (j = y; j < y + 10; ++j)
      {
	      p[i][j] = 1;
      }
    }
    --n;
  }
  int maxA = 0;
  int k;
  for (i = 0; i < 100; ++i)
  {
    for (j = 0; j < 100; ++j)
    {
      if (p[i][j])
      {
	      p[i][j] += p[i-1][j];
      }
    }
  }
  for (i = 0; i < 100; ++i)
  {
    for (j = 0; j < 100; ++j)
    {
      int l = 100;
      int w = 1;
      for (k = j; k > 0 && p[i][k] > 0; --k, ++w)
      {
        if (p[i][k] < l)
        {
          l = p[i][k];
        }
        if (maxA < l * w)
        {
          maxA = l * w;
        }
      }
    }
  }
  printf("%d\n", maxA);
}
