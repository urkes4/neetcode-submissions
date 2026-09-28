class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, j;
        int n = nums.size();
        int ans = 0;
        for(i=0;i<n;i++){
            int sum = 0;
            for(j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)  ans++;
            }
        }
        return ans;
    }
};