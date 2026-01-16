// leetcode problem link are given below

// https://leetcode.com/problems/minimum-path-sum/


// dp memoization is used here

// class Solution {
//     int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
//         if(!row && !col){
//             return grid[row][col];
//         }
//         if(row < 0 || col < 0) return INT_MAX;

//         if(dp[row][col] != -1) return dp[row][col];

//         long long up = (long long)grid[row][col] + solve(row-1,col,grid,dp);
//         long long left = (long long)grid[row][col] + solve(row,col-1,grid,dp);
//         return dp[row][col] = int(min(up,left));
        
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         vector<vector<int>> dp(row,vector<int>(col,-1));
//         return solve(row-1,col-1,grid,dp);
//     }
// };


//  do tabulation to overcome from the recursive stack space

// here space complexity is 0(m*n)

// this is most satisfied solution for most of the interview



// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         vector<vector<int>> dp(row,vector<int>(col,0));

//         for(int i = 0;i<row;i++){
//             for(int j = 0;j<col;j++){
//                 if(!i && !j){
//                     dp[i][j] = grid[i][j];
//                     continue;
//                 }
//                 int up = 1e7;
//                 int left = 1e7;
//                 if(i > 0) up = dp[i-1][j] + grid[i][j];
//                 if(j > 0) left = dp[i][j-1] + grid[i][j];
//                 dp[i][j] = min(up,left);
//             }
//         }
//         return dp[row-1][col-1];
//     }
// };





// but we can optimise it upto the 0(max(n,m));
// time complexity = 0(n*m) n -> no of row. m-> no of col in the grid
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> prev_row(row,0);

        for(int i = 0;i<row;i++){
            vector<int>temp(col,0);
            for(int j = 0;j<col;j++){
                if(!i && !j){
                    temp[j] = grid[i][j];
                    continue;
                }
                int up = 1e7;
                int left = 1e7;
                if(i > 0) up = grid[i][j] + prev_row[j];
                if(j > 0) left = grid[i][j] + temp[j-1];
                temp[j] = min(up , left);
            }
            prev_row = temp;
        }
        return prev_row.back();  // this is best practice 
        // return prev_row[col-1];
    }
};
