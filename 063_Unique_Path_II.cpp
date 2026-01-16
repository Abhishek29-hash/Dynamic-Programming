// memoization dp 

// time complexity = 0(n*m);

// space complexity = 0(n(*m) + 0((n-1)+(m-1)))


//   **********   code    ***********


// class Solution {
//     int solve(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
//         if(row < 0 || col < 0 || obstacleGrid[row][col] == 1) return 0;
//         else if(!row && !col) return 1;
        
//         if(dp[row][col] != -1) return dp[row][col];

//         int up = solve(row-1,col,obstacleGrid,dp);
//         int left = solve(row,col-1,obstacleGrid,dp);
//         return dp[row][col] = up+left;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int row = obstacleGrid.size();
//         int col = obstacleGrid[0].size();

//         vector<vector<int>> dp(row,vector<int>(col,-1));
//         return solve(row-1,col-1,obstacleGrid,dp);    
//     }
// };

// tabulation here space is optimised by recursive stack space


//    ************.   code.       ************

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row_n = obstacleGrid.size();
        int col_n = obstacleGrid[0].size();

        vector<vector<int>> dp(row_n,vector<int>(col_n,-1));
        
        for(int row = 0;row < row_n;row++){
            for(int col = 0;col < col_n;col++){
                if(!row && !col && !obstacleGrid[row][col]){
                    dp[row][col] = 1;
                    continue;
                }

                // if we encounter a obstcle then we have 0 path from that block 

                if(obstacleGrid[row][col]){ 
                    dp[row][col] = 0;
                    continue;
                }

               int up = 0, left = 0;

               if(row > 0) up = dp[row-1][col];
               if(col > 0) left = dp[row][col-1];

               dp[row][col] = up+left;
            }
        }
        return dp[row_n-1][col_n-1];
    }
};
