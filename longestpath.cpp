#include <bits/stdc++.h>

using namespace std;
const int mxN=1000;
vector<pair<int , int>> adj[mxN];
int dp[mxN];

void dfs(int u, int p) {
    dp[u] = 0;
    for (auto e : adj[u]) {
        int v = e.first, w = e.second;
        if (v != p) {
            dfs(v, u);
            dp[u] = max(dp[u], dp[v] + w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) { //m>n-1 will have cycle
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;

    return 0;
}