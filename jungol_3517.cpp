
#include <stdio.h>

int arr[500000];
int Q[500000];

int binarySearchRecur (int A[], int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;

    if (A[mid] == target) {
        return mid;
    }

    if (A[mid] > target)
        return binarySearchRecur(A, low, mid-1, target);

    return binarySearchRecur(A, mid+1, high, target);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i < n; i++)
        scanf("%d", &arr[i]);   // 오름 차순으로 구성

    int qn;
    scanf("%d", &qn);
    for (int i=0; i < qn; i++)
        scanf("%d", &Q[i]); // 찾고자 하는 랜덤 수로 구성

    for (int i=0; i < qn; i++)
    {
        int ret = binarySearchRecur(arr, 0, n - 1, Q[i]);
        printf("%d ", ret);
    }
    printf("%n");

    return 0;
}
