#include <bits/stdc++.h>

using namespace std;
int n, e, ans;
vector<int> g[3001];
queue<pair<int, string>> q;
set<pair<int, string>> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> e;
    int u, v;
    for(int i=0; i<e; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    string visitt(n, '0'), allvisitt(n, '1');
    for(int i=0; i<n; i++){
        visitt[i]='1';
        q.push({i, visitt});
        s.insert({i, visitt});
        visitt[i]='0';
    }
    
    char tempvisitt;
    while(!q.empty()){
        int ss=q.size();
        ans++;
        while(ss--){
            int node=q.front().first;
            string visittnow=q.front().second;
            q.pop();
            for(int i=0; i<g[node].size(); i++){
                tempvisitt=visittnow[g[node][i]];
                visittnow[g[node][i]]='1'; //visitt
                if(visittnow==allvisitt) {
                    cout << ans;
                    return 0;
                }
                if(!s.count({g[node][i], visittnow})){
                    q.push({g[node][i],visittnow});
                    s.insert({g[node][i], visittnow});
                }
                visittnow[g[node][i]]=tempvisitt;
            }
        }
    }

    return 0;
}