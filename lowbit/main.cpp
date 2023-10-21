#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N  (1 << 20)
int H[MAX_N + 1];

void init(void){
    for (int i = 0; i < 20; i++)
        H[1 << i] = i;
}


int lowbit(int x){
    return x & -x;
}

int main(void){
    init();
    
    int n;
    scanf("%d", &n);
    while (n > 0){
        printf("%d ", H[lowbit(n)]);
        n = n - lowbit(n);
    }
    putchar('\n');
    return 0;
}