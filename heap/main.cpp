#include <iostream>
#include <cstdio>
#include <algorithm>


void down(int heap[], int i, int size){
    int t = i;
    if (i * 2 <= size && heap[t] > heap[i * 2]) t = i * 2;
    if (i * 2 + 1 <= size && heap[t] > heap[i * 2 + 1]) t = i * 2 + 1;
    if (t != i){
        swap(heap[t], heap[i]);
        down(heap, t, size);
    }
}
void up(int heap[], int i){
    while (i / 2 && heap[i] > heap[i / 2]){
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

int main(void){
    size = 6;
    int h[7] = {0, 6, 5, 4, 3, 2, 1};
    for (int i = size / 2; i; i--)
        down(h, i, 6);
    while (size){
        swap(h[1], h[size]);
        size--;
        down(h, 1, size);
    }
    for (int i = 1; i <= 6; i++)
        printf("%d ", h[i]);
    putchar('\n');

    

    return 0;
}
