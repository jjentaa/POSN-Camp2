#include <bits/stdc++.h>
using namespace std;
int n, m, nu;
bitset<2001> g[10001], visitt[10001];
int row[]={1, 1, 1, 0, 0, -1, -1, -1};
int col[]={1, 0, -1, 1, -1, 1, 0, -1};
int counter;
int ans;
char sth;
queue<pair<int, int>> q;
int isValid(int x, int y){
    if(x<1 || y<1 || x>m || y>n || !g[x][y] || visitt[x][y]) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> sth;
            if(sth=='1') g[i][j]=true;
            else g[i][j]=false;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(!isValid(i, j)) continue;
            q.push({i, j});
            counter=1;
            while(!q.empty()){
                int x=q.front().first, y=q.front().second;
                q.pop();
                visitt[x][y]=true;
                for(int d=0; d<4; d++){
                    if(isValid(x+row[d], y+col[d])){
                        visitt[x+row[d]][y+col[d]]=true;
                        q.push({x+row[d], y+col[d]});
                        counter++;
                    }
                }
            }
            //cout << counter << " ";
            if(counter>1) ans++;
        }
    }
    cout << ans;
    
    return 0;
}