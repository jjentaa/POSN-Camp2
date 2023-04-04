#include <bits/stdc++.h>

using namespace std;
int n, m;
int g[1001][1001];
int row[]={0, 0, -1, 1};
int col[]={-1, 1, 0, 0};
vector<pair<int, pair<int, int>>> tree; // val, {x, y}

// bool comp(const pair<int, pair<int, int>> p1, const pair<int, pair<int, int>> p2){
//     return p1.first<p2.first;
// }

int findDis(pair<int, int> st, pair<int, int> ed){
    vector<vector<int>> visitt(n,vector<int>(m,0));
    visitt[st.first][st.second]=1;
    int dist=0;
    queue<pair<int, int>> q;
    q.push(st);

    while(!q.empty()){
        dist++;
        int ss=q.size();
        while(ss--){
            pair<int, int> now=q.front();
            q.pop();
            if(now==ed) return dist-1;
            for(int d=0; d<4; d++){
                int newX=now.first+row[d], newY=now.second+col[d];
                if(newX<0 || newY<0 || newX>=n || newY>=m) continue;
                if(visitt[newX][newY]) continue;
                if(g[newX][newY]==0) continue;
                q.push({newX, newY});
                visitt[newX][newY]=1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j]>1) tree.push_back({g[i][j], {i, j}});
        }
    }

    sort(tree.begin(), tree.end());

    pair<int, int> start={0, 0};
    int ans=0;
    for(int i=0; i<tree.size(); i++){
        int dd=findDis(start, tree[i].second);
        if(dd==-1){
            cout << -1;
            return 0;
        }
        ans+=dd;
        start=tree[i].second;
    }

    cout << ans;
    return 0;
}