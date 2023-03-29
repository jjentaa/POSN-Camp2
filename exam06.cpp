#include <bits/stdc++.h>

using namespace std;
int r, c;
int counter=0, ans=0;
int row[]={-1, -1, -1, 1, 1, 1, 0, 0};
int col[]={-1, 0, 1, -1, 0, 1, -1, 1};
queue<pair<int, int>> q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    int g[r+1][c+1];
    bool visitt[r+1][c+1];
    memset(visitt, false, sizeof(visitt));
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> g[i][j];
            if(g[i][j]==0) visitt[i][j]=true;
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(visitt[i][j]) continue;
            counter=1;
            visitt[i][j]=true;
            q.push({i, j});
            while(!q.empty()){
                int x=q.front().first, y=q.front().second;
                visitt[x][y]=true;
                q.pop();
                for(int d=0; d<8; d++){
                    int newX=x+row[d], newY=y+col[d];
                    if(newX<1 || newX>r || newY<1 || newY>c || visitt[newX][newY]) continue;
                    counter++;
                    q.push({newX, newY});
                    visitt[newX][newY]=true;
                }
            }
            ans=max(ans, counter);
        }
    }

    cout << ans;

    return 0;
}