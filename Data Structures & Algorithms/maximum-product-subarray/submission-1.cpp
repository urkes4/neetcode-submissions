class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp_max(n);
        vector<int> dp_min(n);

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int num1 = nums[i] * dp_max[i - 1];
            int num2 = nums[i] * dp_min[i - 1];
            int num3 = nums[i];

            dp_max[i] = max({num1, num2, num3});
            dp_min[i] = min({num1, num2, num3});

            ans = max(ans, dp_max[i]);
        }

        return ans;
    }
};