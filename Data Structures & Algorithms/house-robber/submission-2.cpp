class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)    return nums[0];
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int i;
        for(i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
