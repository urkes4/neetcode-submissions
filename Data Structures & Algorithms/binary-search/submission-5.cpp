class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, d;
        l = 0;
        d = nums.size()-1;
        while(l<=d){
            int mid = (l+d)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                d=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};
