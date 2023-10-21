#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m;
bool vis[N];

int dijkstra(void){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        vis[t] = true;

        for (int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main(void){
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = i == j ? 0 : INF;
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    printf("%d\n", dijkstra());

    return 0;
}

