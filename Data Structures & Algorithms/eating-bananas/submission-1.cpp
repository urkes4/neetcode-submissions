class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int d = *max_element(piles.begin(), piles.end());

        while (l <= d) {
            int mid = (l + d) / 2;
            int total = 0;

            for (auto &p : piles) {
                total += p / mid;
                if (p % mid != 0)
                    total++;
            }

            if (total <= h) {
                d = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};