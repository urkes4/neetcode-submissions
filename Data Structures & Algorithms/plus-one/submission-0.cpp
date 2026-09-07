class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;
        int carry = (digits[index]+1)/10;
        while(index>=0){
            carry = (digits[index]+1)/10;
            digits[index] = (digits[index]+1)%10;
            index--;
            if(!carry){
                return digits;
            }
        }
        if(carry){
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }
        return digits;
    }
};
