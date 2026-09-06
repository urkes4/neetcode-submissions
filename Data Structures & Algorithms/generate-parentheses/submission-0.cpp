class Solution {
public:
    vector<string>ans;
    void helper(int n, int open, int closed, string cur){
        if(open==n && closed==n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            helper(n, open+1, closed, cur+"(");
        }
        if(closed<open){
            helper(n, open, closed+1, cur+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(n, 0, 0, "");
        return ans;
    }
};
