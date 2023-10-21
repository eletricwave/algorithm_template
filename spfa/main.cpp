#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int e[N], ne[N], w[N], h[N], dist[N], idx, n, m;
bool vis[N];

void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa(void){
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    vis[1] = true;

    while (q.size()){
        int x = q.front();
        q.pop();
        vis[x] = false;

        for (int i = h[x]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[x] + w[i]){
                dist[j] = dist[x] + w[i];
                if (!vis[j]){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    
    if (dist[n] == INF)
        return -1;
    return dist[n];
}

int main(void){
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int  t = spfa();
    if (t == -1)
        printf("impossible\n");
    else
        printf("%d\n", t);

    return 0;
}
