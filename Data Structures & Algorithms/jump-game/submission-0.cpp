class Solution {
public:

    bool canJump(vector<int>& nums) {
        int i;
        int cur = nums.size()-1;
        for(i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=cur){
                cur = i;
            }
        }
        return cur==0;
    }
};
