#include <iostream>
#include <cstdio>

const int N = 100010, M = N * 2;

int h[N], e[M], ne[M], idx;
bool vis[M];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int p){
    vis[p] = true;
    for (int i = h[p]; i != -1; i = ne[i]){
        if (!!vis[ne[i]])
            dfs(ne[i]);
    }
}

int main(void){
    memset(h, -1, sizeof(h));
    


    return 0;
}
