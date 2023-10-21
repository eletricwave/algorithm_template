#include <cstdio>
#include <iostream>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int dist[N][N], n, m, q;

void floyd(void){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}

int main(void){
    scanf("%d%d%d", &n, &m, &q);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = i == j ? 0 : INF;
    
    for (int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        dist[x][y] = min(dist[x][y], z);
    }

    floyd();

    while (q--){
        int a, b;
        scanf("%d%d", &a, &b);
        if (dist[a][b] > INF / 2)
            printf("impossible\n");
        else
            printf("%d\n", dist[a][b]);
    }

    return 0;
}

