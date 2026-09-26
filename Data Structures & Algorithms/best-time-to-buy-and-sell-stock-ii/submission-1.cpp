class Solution {
public:

    int helper(vector<int>&prices, int index, int state, vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][state]!=-1){
            return dp[index][state];
        }
        int ans = helper(prices, index+1, state, dp);
        if(state==0){
            ans = max(ans, helper(prices,index+1,1, dp)-prices[index]);
        }
        else{
            ans = max(ans, helper(prices,index+1,0, dp)+prices[index]);
        }
        dp[index][state] = ans;
        return dp[index][state];
    }

    int maxProfit(vector<int>& prices) { 
        vector<vector<int>>dp(prices.size(), vector<int>(2,-1));   
        return helper(prices, 0, 0, dp);
    }
};