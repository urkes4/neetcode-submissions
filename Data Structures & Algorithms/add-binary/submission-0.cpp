class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i1 = a.size() - 1;
        int i2 = b.size() - 1;
        int carry = 0;

        while (i1 >= 0 || i2 >= 0 || carry) {
            int num1 = (i1 >= 0 ? a[i1] - '0' : 0);
            int num2 = (i2 >= 0 ? b[i2] - '0' : 0);

            int sum = num1 ^ num2 ^ carry;
            int count = (num1 & 1) + (num2 & 1) + (carry & 1);

            carry = count > 1;

            char c = (sum == 1 ? '1' : '0');
            res.push_back(c);

            i1--;
            i2--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};