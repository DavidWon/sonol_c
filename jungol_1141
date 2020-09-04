#include <stdio.h>
#include <stdlib.h>
 
void main() {
 
    int a, i, j, count = 0;
    int *arr;
 
    scanf("%d", &a);
 
    arr = (int *)malloc(sizeof(int)*a);
 
    for (i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
    /* 배열 출력
    for (i = 0; i < a; i++) {
        printf("%d ", arr[i]);
    }
    */
 
    // 앞에 소가 크면 카운트 업, 같거나 작으면 break로 빠져나옴.
    for (i = 0; i < a - 1; i++) {
        for (j = i + 1; j < a; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
            else {
                break;
            }
        }
    }
    printf("%d", count);
    free(arr);
 
}
