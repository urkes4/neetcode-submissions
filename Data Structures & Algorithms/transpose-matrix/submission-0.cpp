class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int i,j;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};