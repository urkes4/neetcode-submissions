class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZeros = 0;
        vector<int>ans;
        int product = 1;
        for(int num:nums){
            if(!num){
                countZeros++;
            }
            else{
                product*=num;
            }
        }
        if(countZeros>=2){
            for(int i =0;i<nums.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
        else if(countZeros==1){
            for(int i =0;i<nums.size();i++){
                if(nums[i]==0){
                    ans.push_back(product);
                }
                else ans.push_back(0);
            }
            return ans;
        }
        else{
            for(int num:nums){
                ans.push_back(product/num);
            }
            return ans;
        }
    }
};
