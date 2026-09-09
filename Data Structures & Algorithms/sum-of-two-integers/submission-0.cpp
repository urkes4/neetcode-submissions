class Solution {
public:
    int getSum(int a, int b) {
        int pos = 0;
        int cnt = 32;
        int res = 0;
        int carry = 0;
        while (cnt--) {
            int mask = 1 << pos;

            int bitA = (a & mask) ? 1 : 0;
            int bitB = (b & mask) ? 1 : 0;

            int sum = bitA ^ bitB ^ carry;

            if (sum)
                res |= mask;

            carry = (bitA & bitB) |
                    (bitA & carry) |
                    (bitB & carry);

            pos++;
        }

        return res;
    }
};