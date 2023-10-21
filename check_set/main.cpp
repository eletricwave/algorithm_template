#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010;
int p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);  //路径压缩
    return p[x];
}

int main(void){
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        p[i] = i;
    }

    char op[2];
    int a, b;
    while (m--){
        while (getchar() != '\n');
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'M')
            p[find(a)] = find(b);
        else
            if (find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
    }

    return 0;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> dp(n + 2, 0);
    for (int i = 0; i < n; i++){
        dp[i + 2] = max(dp[i + 1], dp[i] + nums[i]);
    }
    
    return dp[n + 1];
}
