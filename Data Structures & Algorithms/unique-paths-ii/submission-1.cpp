class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        int i,j;
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(i=0;i<m;i++){
            if(obstacleGrid[i][0]==1)   break;
            dp[i][0] = 1;
        }
        for(i=0;i<n;i++){
            if(obstacleGrid[0][i]==1)   break;
            dp[0][i] = 1;
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)   continue;
                if(obstacleGrid[i-1][j]!=1){
                    dp[i][j]+=dp[i-1][j];
                }
                if(obstacleGrid[i][j-1]!=1){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};