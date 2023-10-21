#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 200010;
int n, m;
int p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);

    return p[x];
}

struct Edge{
    int a, b, w;
    bool operator < (const Edge &W) const{
        return w < W.w;
    }
}edge[N];


int main(void){
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }

    sort(edge, edge + m);

    for (int i = 0; i < n; i++)
        p[i] = i;
    
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);

        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    if (cnt < n - 1) puts("impossible\n");
    else printf("%d\n", res);

    return 0;
}

