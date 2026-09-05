class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       // transpose first
       int i,j;
       int m, n;
       m = matrix.size();
       n = matrix[0].size();
       for(i=0;i<m;i++){
            for(j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
       } 
       for(i=0;i<m;i++){
        for(j=0;j<n/2;j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
       }
    }
};
