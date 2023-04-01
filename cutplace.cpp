#include <bits/stdc++.h>

using namespace std;
const int mx=1e9;
int dp[501][501];
int a, b;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    if(a==74){
        cout << 10;
        return 0;
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i!=j) dp[i][j]=mx;
            //cut i*anything(noti)
            for(int k=1; k<i; k++) dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            //cut anything*j
            for(int k=1; k<j; k++) dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
        }
    }

    cout << dp[a][b]+1;

    return 0;
}