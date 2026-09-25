class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = -1;
        int cnt = 0;
        unordered_map<int, int>mp;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>cnt){
                cnt = mp[num];
                cand = num;
            }
        }
        return cand;
    }
};