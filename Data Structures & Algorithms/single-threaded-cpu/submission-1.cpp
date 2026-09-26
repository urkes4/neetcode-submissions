class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int, 3>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(v.begin(), v.end());

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans;

        long long timestamp = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            if (pq.empty() && timestamp < v[i][0]) {
                timestamp = v[i][0];
            }

            while (i < n && v[i][0] <= timestamp) {
                pq.push({v[i][1], v[i][2]});
                i++;
            }

            auto [processingTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);

            timestamp += processingTime;
        }

        return ans;
    }
};

