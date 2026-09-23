class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        int i;
        dp[0] = 0;
        dp[1] = 1;
        for(i=1;i<=n;i++){
            int j;
            for(j=1;j*j<=i;j++){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};