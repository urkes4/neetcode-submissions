class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            if(nums[i]>0)   break;
            if(i>0 && nums[i]==nums[i-1])   continue;
            int l,d;
            l = i+1;
            d= nums.size()-1;
            while(l<d){
                int suma = nums[l]+nums[d]+nums[i];
                if(suma==0){
                    ans.push_back({nums[i], nums[l], nums[d]});
                    l++;
                    d--;
                    while(l<d && nums[l]==nums[l-1])l++;
                }
                else if(suma>0){
                    d--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};
