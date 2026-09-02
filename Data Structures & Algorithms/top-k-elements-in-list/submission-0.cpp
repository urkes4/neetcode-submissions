class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        for(auto&p:mp){
            pq.push({p.second,p.first});
        }
        vector<int>ans;
        while(k--){
            int elem = pq.top().second;
            pq.pop();
            ans.push_back(elem);
        }
        return ans;
    }
};
