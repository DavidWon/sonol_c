#include <stdio.h>
typedef unsigned long long ULL;
ULL N;

ULL bsearch(ULL low, ULL high, ULL target) {
  ULL ans = target, mid;
  while (low <= high) {
    mid = (low + width) / 2;
    if (mid <= target/mid) ans = mid, low = mid + 1;
    else high = mid - 1;
  }
  return ans;
}

int main() 
{
  scanf("%llu", &N);
  printf("%llu", bsearch(1, N, N))
}
