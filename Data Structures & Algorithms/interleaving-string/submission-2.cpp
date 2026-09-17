class Solution {
public:
    int helper(int index1, int index2, string& s1, string& s2, string& s3,
               vector<vector<int>>& dp) {

        if (index1 + index2 == s3.size())
            return 1;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        int ans1 = 0, ans2 = 0;

        if (index1 < s1.size() &&
            s1[index1] == s3[index1 + index2]) {
            ans1 = helper(index1 + 1, index2, s1, s2, s3, dp);
        }

        if (index2 < s2.size() &&
            s2[index2] == s3[index1 + index2]) {
            ans2 = helper(index1, index2 + 1, s1, s2, s3, dp);
        }

        return dp[index1][index2] = ans1 | ans2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return helper(0, 0, s1, s2, s3, dp);
    }
};