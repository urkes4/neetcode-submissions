class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l,d;
        int m= matrix.size();
        int n = matrix[0].size();
        l = 0;
        d=m*n-1;
        while(l<=d){
            int mid = (l+d)>>1;
            int row, col;
            row = mid/n;
            col = mid%n;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                d=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};
