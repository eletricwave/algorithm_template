#include <iostream>
#include <cstdio>

using namespace std;

void qsort(int nums[], int l, int r){
    if (l == r)
        return;
    
    int x = nums[l], i = l - 1, j = r + 1;

    while (i < j){
        do i++; while (nums[i] < x);
        do j--; while (nums[j] > x);

        if (i < j)  swap(nums[i], nums[j]);
    }

    qsort(nums, l, j);
    qsort(nums, j + 1, r);
}

int main(void){
    int nums[] = {4 ,3, 2, 1};

    printf("before quick sort:\n");
    for (int i = 0 ;i < 4; i++)
        printf("%d\t", nums[i]);
    putchar('\n');
    
    qsort(nums, 0, 3);

    printf("after quick sort:\n");
    for (int i = 0; i < 4; i++)
        printf("%d\t", nums[i]);
    putchar('\n');

    return 0;
}