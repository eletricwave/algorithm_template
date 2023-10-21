#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


using ll = long long;
const int MAXN = 100010;
ll n, m, a[MAXN * 4], tree[MAXN * 4], mark[MAXN * 4];

inline ll read(void){
    ll ans = 0;
    char c = getchar();
    while (!isdigit(c))  c = getchar();
    while (isdigit(c)){
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

inline void push_down(ll p, ll len){
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;
}

void build(ll l = 1, ll r = n, ll p = 1){
    if (l == r) tree[p] = a[l];
    else{
        ll mid = (l + r) >> 1;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

void up_data(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n){
    if (cr < l || cl > r) return;
    else if(cr <= r && cl >= l){
        tree[p] += d * (cr - cl + 1);
        if (cr > cl) mark[p] += d;
    }
    else{
        ll mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1);
        up_data(l, r, d, p * 2, cl, mid);
        up_data(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n){
    if (cl > r || cr < l) return 0;
    else if(cl >= l && cr <= r) return tree[p];
    else{
        ll mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1);
        return query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr);
    }
}

int main(void){
    n = read();
    m = read();

    for (int i = 1; i <= n; i++) a[i] = read();

    build();
    for (int i = 0; i < m; i++){
        ll op = read(), l = read(), r = read();
        if (op == 1){
            ll d = read();
            up_data(l, r, d);
        }
        else printf("%lld\n", query(l, r));
    }

    return 0;
}
