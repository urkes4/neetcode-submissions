class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> mp;

        for (int num : nums) {
            mp.insert(num);
        }

        int ans = 1;

        while (mp.find(ans) != mp.end()) {
            ans++;
        }

        return ans;
    }
};