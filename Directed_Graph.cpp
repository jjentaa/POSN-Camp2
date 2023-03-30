#include <bits/stdc++.h>

using namespace std;
int n, e, u, v, k, s, t, ans;
vector<int> adj[100000];

void dfs(int j, int counter){
    if(j==v){
        if(counter<=k) ans++;
        return ;
    }
    for(auto ed:adj[j]){
        dfs(ed, counter+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> s >> t;
        adj[s].push_back(t);
    }
    cin >> u >> v >> k;

    dfs(u, 0);
    cout << ans;

    return 0;
}