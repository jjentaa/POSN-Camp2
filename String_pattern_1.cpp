#include <bits/stdc++.h>

using namespace std;
int countSubsequences(string word, string pattern) {
    int m = pattern.length();
    int n = word.length();
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = 1;
            
            else if (j == 0) dp[i][j] = 0;
            
            else if (pattern[i-1] == word[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];

            else dp[i][j] = dp[i][j-1];
        }
    }

    return dp[m][n];
}

string txt, patt;
int main() {
    cin >> txt >> patt;

    cout << countSubsequences(txt, patt);

    return 0;
}

/*
    s u b s e q u e n c e
  0 1 1 1 1 1 1 1 1 1 1 1
s 0 1 1 1 2 2 2 2 2 2 2 2
u 0 0 1 1 1 1 1 1 1 1 1 1
e 0 0 0 0 1 1 1 1 1 1 1 2

*/