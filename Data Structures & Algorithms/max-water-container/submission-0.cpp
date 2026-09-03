class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int d = heights.size()-1;
        int ans = INT_MIN;
        while(l<d){
            ans = max(ans, min(heights[l], heights[d])*(d-l));
            if(heights[l]<heights[d]){
                l++;
            }
            else d--;
        }
        return ans;
    }
};
