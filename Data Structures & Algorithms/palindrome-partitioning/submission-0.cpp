class Solution {
public:

    bool isPalindrome(string s){
        int l = 0;
        int d = s.size()-1;
        while(l<=d){
            if(s[l]!=s[d]){
                return false;
            }
            l++; d--;
        }
        return true;
    }

    void helper(int index, string s, vector<vector<string>>&ans, vector<string>&cur){
        if(index==s.size()){
            ans.push_back(cur);
            return;
        }
        int len;
        for(len = 1;len<=s.size()-index;len++){
            if(isPalindrome(s.substr(index, len))){
                cur.push_back(s.substr(index, len));
                helper(index+len, s, ans, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        helper(0, s, ans, cur);
        return ans;
    }
};
