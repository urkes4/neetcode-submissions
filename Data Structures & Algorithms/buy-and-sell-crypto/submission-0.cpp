class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int ans = 0;
        for(int& p:prices){
            if(p<buy){
                buy = p;
                sell = buy;
            }
            else{
                sell = p;
            }
            ans = max(ans, sell-buy);
        }
        return ans;
    }
};
