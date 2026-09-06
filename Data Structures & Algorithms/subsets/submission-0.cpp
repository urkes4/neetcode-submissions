class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans,
                vector<int>& cur, int index) {

        if (index == nums.size()) {
            ans.push_back(cur);
            return;
        }

        helper(nums, ans, cur, index + 1);

        cur.push_back(nums[index]);
        helper(nums, ans, cur, index + 1);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        helper(nums, ans, cur, 0);

        return ans;
    }
};