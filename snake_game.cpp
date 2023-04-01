#include <bits/stdc++.h>

using namespace std;

int n, l, s;
int step[102];
bool visitt[102];
queue<pair<int, int>> q; //{position, roll}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> s;
    memset(step, -1, sizeof(step));

    for(int i=0; i<l+s; i++){
        int st, ed;
        cin >> st >> ed;
        step[st]=ed;
    }

    visitt[0]=true;
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> ans=q.front();
        q.pop();
        if(ans.first==n-1){
            cout << ans.second;
            return 0;
        }
        for(int d=1; d<=6&&(ans.first+d)<n; d++){
            if(visitt[ans.first+d]) continue;
            visitt[ans.first+d]=true;
            if(step[ans.first+d]!=-1) q.push({step[ans.first+d], ans.second+1}); //snake or ladder
            else q.push({ans.first+d, ans.second+1});
        }
    }

    return 0;
}