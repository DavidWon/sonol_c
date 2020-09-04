#include <stdio.h>
#include <stack>
#pragma warning(disable:4996)
 
using namespace std;
 
typedef struct _fac
{
    int idx;
    int val;
}fac;
 
int n, cnt;
fac building[500005];
stack<fac> box;
int answer[500005];
 
int main()
{
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");
 
    fscanf(fin, "%d", &n);
    cnt = n;
    for (int i = 1; i <= n; i++)
    {
        fscanf(fin, "%d", &building[i].val);        
        building[i].idx = i;
    }
 
    box.push(building[n]);
    for (int i = n-1; i >= 1; i--)
    {
        while (1)
        {
            if (box.empty())
            {
                box.push(building[i]);
                break;
            }
            else if (box.top().val < building[i].val)
            {
                answer[box.top().idx] = building[i].idx;
                box.pop();
            }
            else if (box.top().val > building[i].val)
            {
                box.push(building[i]);
                break;
            }
        }
    }
 
    for (int i = 1; i <= n; i++)
        fprintf(fout, "%d ", answer[i]);
    fprintf(fout, "\n");
}
