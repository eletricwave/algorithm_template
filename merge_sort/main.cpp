#include <iostream>

using namespace std;

int tmp[10000];

void merge_sort(int nums[], int l, int r){
    if (l >= r)
        return;
    
    int mid = l + r >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
        else tmp[k++] = nums[j++];
    
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        nums[i] = tmp[k];
}

int main(void){
    int nums[] = {4 ,3, 2, 1};

    printf("before quick sort:\n");
    for (int i = 0 ;i < 4; i++)
        printf("%d\t", nums[i]);
    putchar('\n');
    
    merge_sort(nums, 0, 3);

    printf("after quick sort:\n");
    for (int i = 0; i < 4; i++)
        printf("%d\t", nums[i]);
    putchar('\n');

    return 0;
}