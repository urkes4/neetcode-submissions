class Solution {
public:
    void helper(vector<vector<int>>&ans, vector<int>cur, int n, int k){
        if(cur.size()==k){
            ans.push_back(cur);
            return;
        }
        int elem;
        if(cur.size()){
            elem = cur[cur.size()-1];
        }
        else elem = 0;
        int i;
        for(i=elem+1;i<=n;i++){
            cur.push_back(i);
            helper(ans, cur, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        helper(ans, {}, n, k);
        return ans;        
    }
};