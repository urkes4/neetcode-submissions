class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int i,j;
        // check rows
        for(i=0;i<9;i++){
            vector<int>nums(10,0);
            for(j=0;j<9;j++){
                if(board[i][j]=='.')    
                    continue;
                if(nums[board[i][j]-'0']){
                    return false;
                }
                nums[board[i][j]-'0'] = 1;
            }
        }
        // check columns
        for(j=0;j<9;j++){
            vector<int>nums(10,0);
            for(i=0;i<9;i++){
                if(board[i][j]=='.')    
                    continue;
                if(nums[board[i][j]-'0']){
                    return false;
                }
                nums[board[i][j]-'0'] = 1;
            }
        }
        // check blocks
        for(int k = 0;k<9;k++){
            vector<int>nums(10,0);
            for(i=(k/3)*3;i<(k/3)*3+3;i++){
                for(j=(k%3)*3;j<(k%3)*3+3;j++){
                    if(board[i][j]=='.')    
                        continue;
                    if(nums[board[i][j]-'0']){
                        return false;
                    }
                    nums[board[i][j]-'0'] = 1;
                }
            }
        }
        return true;
    }
};
