class Solution {
public:
    string findPrefix(string& s1, string& s2){
        string ans = "";
        int i,j;
        i = j = 0;
        while(i<s1.size() && j<s2.size() && s1[i]==s2[j]){
            ans+=s1[i];
            i++; j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        string ans = strs[0];
        for(i=1;i<strs.size();i++){
            ans = findPrefix(ans, strs[i]);
        }
        return ans;
    }
};