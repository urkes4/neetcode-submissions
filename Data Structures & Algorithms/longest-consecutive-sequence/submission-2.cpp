class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())    return 0;
        unordered_set<int>mp;
        int ans = 1;
        for(int num:nums){
            mp.insert(num);
        }
        for(int num:nums){
            int cur = 1;
            if(mp.find(num-1)==mp.end()){
                int length = 1;
                while (mp.find(num + length) != mp.end()) {
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
