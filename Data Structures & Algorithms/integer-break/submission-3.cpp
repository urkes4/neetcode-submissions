class Solution {
    unordered_map<int, int> dp;

public:
    int integerBreak(int n) {
        dp[1] = 1;
        return dfs(n, n);
    }

private:
    int dfs(int num, int n) {
        if (dp.find(num) != dp.end()) {
            return dp[num];
        }

        int res = (num == n) ? 0 : num;
        for (int i = 1; i < num; i++) {
            int val = dfs(i, n) * dfs(num - i, n);
            res = max(res, val);
        }

        dp[num] = res;
        return res;
    }
};