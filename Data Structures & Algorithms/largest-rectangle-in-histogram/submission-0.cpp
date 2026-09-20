class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n,n);
        stack<int>st;
        int i;
        for(i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = INT_MIN;
        for(i =0;i<n;i++){
            left[i]++;
            right[i]--;
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};
