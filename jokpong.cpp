#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
string sth;
int n;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    vec.push_back(1);
    getline(cin, sth);
    string num;
    istringstream iss(sth);
    while (getline(iss, num, ' ')) {
        int number=stoi(num);
        vec.push_back(number);
        n++;
    }
    vec.push_back(1);

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int sizee=1; sizee<=n; sizee++){
        for(int i=1; i<=n-sizee+1; i++){
            int l=i, r=i+sizee-1;
            for(int j=l; j<=r; j++){
                int maxx=vec[l-1]*vec[j]*vec[r+1]+dp[l][j-1]+dp[j+1][r];
                dp[l][r]=max(dp[l][r], maxx);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
