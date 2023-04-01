#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vec;
int n, ans=1, counter;

void solve(int w, int h, int counter, int l){
    for(int i=l; i<n; i++){
        if(vec[i].first>w && vec[i].second>h) solve(vec[i].first, vec[i].second, counter+1, i+1);
    }
    ans=max(ans, counter);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int w, h;

    for(int i=0; i<n; i++){
        cin >> w >> h;
        vec.push_back({w, h});
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++) solve(vec[i].first, vec[i].second, 1, i+1);

    cout << ans;

    return 0;
}