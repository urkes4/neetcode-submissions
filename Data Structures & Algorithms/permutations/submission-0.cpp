class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums, vector<bool>used, vector<int>cur){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(!used[i]){
                used[i] = true;
                cur.push_back(nums[i]);
                helper(nums, used, cur);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        helper(nums, used, {});
        return ans;
    }
};
