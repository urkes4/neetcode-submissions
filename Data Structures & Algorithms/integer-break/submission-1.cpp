class Solution {
public:

    int dfs(int n, int cur, int num, vector<vector<int>>& dp) {
        // used num integers and got sum == n
        if (num == 0 && cur == 0) {
            return 1;
        }

        if (num == 0 || cur == 0) {
            return 0;
        }

        if (dp[cur][num] != -1) {
            return dp[cur][num];
        }

        int res = INT_MIN;

        for (int i = 1; i <= n; i++) {
            if (cur - i >= 0) {
                res = max(res, i * dfs(n, cur - i, num - 1, dp));
            }
        }

        return dp[cur][num] = res;
    }

    int integerBreak(int n) {
        int ans = INT_MIN;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int i = 2; i <= n; i++) {
            ans = max(ans, dfs(n, n, i, dp));
        }

        return ans;
    }
};