#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main(void){
    int n, m;
    // 1 ~ n
    scanf("%d%d", &n, &m);
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1), res;  // d represent enter

    while (m--){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        d[b]++;
    }
    queue<int> q;

    for (int i = 1; i < n; i++){
        if (d[i] == 0){
            res.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto e : g[x]){
            d[e]--;
            if (d[e] == 0){
                res.push_back(e);
                q.push(e);
            }
        }
    }

    if (res.size() == n){
        for (auto e : res)
            printf("%d ", e);
    }
    else {
        printf("-1 ");
    }
    putchar('\n');

    return 0;
}


