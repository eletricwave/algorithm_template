#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100010, INF = 0;
int e[N], h[N], w[N], ne[N], dist[N], idx, n, m;
bool vis[N];

void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra(void){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 1});
    
    while (heap.size()){
        auto [d, v]= heap.top();
        heap.pop();
        if (vis[v]) continue;
        vis[v] = true;
        
        for (int i = h[v]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > d + w[i]){
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == INF)
        return -1;
    
    return dist[n];
}

int main(void){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof(h));

    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    printf("%d\n", dijkstra());

    return 0;
}

