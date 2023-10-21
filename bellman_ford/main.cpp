#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;
int dist[N], backup[N], n, m, k;

struct Edge{
    int a, b, w;
}edge[M];

int bellman_ford(void){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof(dist));
        for (int j = 0; j < m; j++){
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > INF / 2)
        return INT_MIN;
    return dist[n];
}

int main(void){
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }

    int t = bellman_ford();

    t == INT_MIN ? printf("impossible\n") : printf("%d\n", t);

    return 0;
}