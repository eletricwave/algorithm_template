#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0X3f3f3f3f;
int h[N], e[N], ne[N], idx;


void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int query(int x){  //开放寻址法
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x){
        k++;
        if (k == N)
            k = 0;
    }

    return k;
}

int main(void){
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof(h));

    while(n--){
        char op[4];
        int x;
        scanf("%s %d", op, &x);
        if (op[0] == 'I'){
            h[query(x)] = x;
        }
        else {
            if (h[query(x)] != null) printf("Yes\n");
            else printf("No\n");
        }
    }

    //拉链法
    // int n;
    // scanf("%d", &n);
    // memset(h, -1,  sizeof(h));
    
    // while (n--){
    //     char op[2];
    //     int x;
    //     scanf("%s%d", op, &x);
    //     if (op[0] == 'I') insert(x);
    //     else {
    //         if (find(x)) puts("Yes");
    //         else puts("No");
    //     }
    // }

    return 0;
}

