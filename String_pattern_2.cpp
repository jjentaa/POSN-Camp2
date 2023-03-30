#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    // it always true
    for(int j = 1; j <= m; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //check if it not '*' and can match include with prev check
            if (p[j-1] != '*') dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j] || dp[i][j-1]; // choose true
            
        }
    }
    return dp[n][m];
}

string s, p;
int main() {
    cin >> s >> p;
    if(isMatch(s, p)) cout << s << " matches " << p << endl;
    else cout << s << " does not match " << p << endl;

    return 0;
}
