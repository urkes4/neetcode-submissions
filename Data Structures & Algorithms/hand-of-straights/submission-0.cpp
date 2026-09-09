class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;

        for(int h : hand)
            mp[h]++;

        for(int i = 0; i < hand.size(); i++){
            if(mp.find(hand[i]) == mp.end())
                continue;

            for(int j = hand[i]; j < hand[i] + groupSize; j++){
                if(mp.find(j) == mp.end())
                    return false;

                mp[j]--;

                if(mp[j] == 0)
                    mp.erase(j);
            }
        }

        return true;
    }
};