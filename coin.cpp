#include <bits/stdc++.h>

using namespace std;
int n, x, c;
int dp[1000001];
const int mod=1e9+7;
vector<int> coins;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> c;
        coins.push_back(c);
    }
    cin >> x;

    dp[0]=1;
    for(int i=0; i<n ; i++){

        c=coins[i] ;
        for(int j=0; j<=10000; j++){ 
            if(j+c<=x){
                dp[j+c]=(dp[j+c]+dp[j]);
            }
        }
    }

    cout << dp[x];

    return 0;
}