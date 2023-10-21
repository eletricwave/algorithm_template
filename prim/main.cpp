#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m;
bool vis[N];

int prim(void){
    memset(dist, 0x3f, sizeof(dist));
    int res = 0;

    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] &&(t == -1 || dist[t] > dist[j]))
                t = j;
            
            if (i && dist[t] == INF) return INF;
            if (i)  res += dist[t];

            for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);

            vis[t] = true;
        
    }

    return res;
}

int main(void){
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d", &n, &m);
    

    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int ans = prim();

    if  (ans == INF) puts("impossible");
    else printf("%d\n", ans);

    return 0;
}
