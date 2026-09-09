class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char c : s1){
            freq1[c - 'a']++;
        }

        // initial window
        int windowSize = s1.size();

        for(int i = 0; i < windowSize; i++){
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2)
            return true;

        for(int i = windowSize; i < s2.size(); i++){
            freq2[s2[i - windowSize] - 'a']--;

            freq2[s2[i] - 'a']++;

            if(freq1 == freq2)
                return true;
        }

        return false;
    }
};