class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int d = n-1;
        while(l<d){
            int mid = (l+d)>>1;
                if(nums[mid]<nums[d]){
                    d = mid;
                }
                else{
                    l = mid+1;
                }
        }
        return nums[l];
    }
};
