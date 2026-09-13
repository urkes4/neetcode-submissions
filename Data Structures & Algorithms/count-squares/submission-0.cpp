class CountSquares {
public:
    unordered_map<int, int> mp;

    int encode(int x, int y) {
        return x * 10000 + y;
    }

    CountSquares() {}

    void add(vector<int> point) {
        mp[encode(point[0], point[1])]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int res = 0;

        for (int d = 1; d <= 1000; d++) {

            if (x + d <= 1000 && y + d <= 1000) {
                res += mp[encode(x + d, y)]
                     * mp[encode(x, y + d)]
                     * mp[encode(x + d, y + d)];
            }

            if (x + d <= 1000 && y - d >= 0) {
                res += mp[encode(x + d, y)]
                     * mp[encode(x, y - d)]
                     * mp[encode(x + d, y - d)];
            }

            if (x - d >= 0 && y + d <= 1000) {
                res += mp[encode(x - d, y)]
                     * mp[encode(x, y + d)]
                     * mp[encode(x - d, y + d)];
            }

            if (x - d >= 0 && y - d >= 0) {
                res += mp[encode(x - d, y)]
                     * mp[encode(x, y - d)]
                     * mp[encode(x - d, y - d)];
            }
        }

        return res;
    }
};