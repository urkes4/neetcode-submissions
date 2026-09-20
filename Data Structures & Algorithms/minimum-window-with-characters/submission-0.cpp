class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq1(128, 0);
        vector<int> freq2(128, 0);

        for (char c : t)
            freq2[c]++;

        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (freq2[i] > 0)
                required++;
        }

        int formed = 0;

        int l = 0;
        int start = -1;
        int ans = INT_MAX;

        for (int r = 0; r < s.size(); r++) {

            char c = s[r];
            freq1[c]++;

            if (freq1[c] == freq2[c])
                formed++;

            while (formed == required) {

                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                freq1[leftChar]--;

                if (freq1[leftChar] < freq2[leftChar])
                    formed--;

                l++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, ans);
    }
};