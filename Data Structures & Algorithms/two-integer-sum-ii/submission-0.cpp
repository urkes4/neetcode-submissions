class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int d = numbers.size()-1;
        while(l<d){
            if(numbers[l]+numbers[d]==target){
                return {l+1,d+1};
            }
            if(numbers[l]+numbers[d]>target)   d--;
            else l++;
        }
        return {};
    }
};
