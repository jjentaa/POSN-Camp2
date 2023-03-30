#include <bits/stdc++.h>

using namespace std;

int count_arrangements(int r, int w, int g) {
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(w + 1, vector<int>(g + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= w; j++) {
            for (int k = 0; k <= g; k++) {
                if (i > 0) {
                    dp[i][j][k] += dp[i - 1][j][k];
                }
                if (j > 0) {
                    dp[i][j][k] += dp[i][j - 1][k];
                }
                if (k > 0) {
                    dp[i][j][k] += dp[i][j][k - 1];
                }
                if (i > 1) {
                    dp[i][j][k] += dp[i - 2][j][k];
                }
                if (j > 1) {
                    dp[i][j][k] += dp[i][j - 2][k];
                }
                if (k > 1) {
                    dp[i][j][k] += dp[i][j][k - 2];
                }
            }
        }
    }

    return dp[r][w][g];
}

int main() {
    int r, w, g;
    cin >> r >> w >> g;

    int count = count_arrangements(r, w, g);

    cout << count << endl;

    return 0;
}
