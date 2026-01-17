// class Solution {
//     int m;
//     int n;

//     int solve(int row, int col1, int col2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
//         // base case out of boundation case 
//         if(col1 >= n || col2 >= n || col1 < 0 || col2 < 0) return 0;

//         if(row == m-1){
//             if(col1 == col2) return grid[row][col1];
//             return grid[row][col1] + grid[row][col2];
//         }

//         int maxi = 0;

//         // we have total 9 combination of the path so

//         if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

//         for(int i = -1;i<=1;i++){
//             for(int j = -1;j<=1;j++){
//                 int val = 0;
//                 if(col1 == col2){
//                     //maxi = max(maxi, grid[row][col1] + solve(row+1,col1+i,col2+j,grid,dp));
//                     val = grid[row][col1];
//                 }
//                 else {
//                     //maxi = max(maxi, (grid[row][col1] + grid[row][col2]) + solve(row+1,col1+i,col2+j,grid,dp));
//                     val = grid[row][col1] + grid[row][col2]; 
//                 }
//                 val += solve(row+1,col1+i,col2+j,grid,dp);
//                 maxi = max(maxi,val);
//             }
//             dp[row][col1][col2] = maxi;
//         }
//         return maxi;

//     }
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
//         return solve(0,0,n-1,grid,dp);
//     }
// };


// tabulation 

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,0)));

        for(int i = 0;i<col;i++){
            for(int j = 0;j<col;j++){
                dp[row-1][i][j] = (i == j)? grid[row-1][j] : grid[row-1][i] + grid[row-1][j];
            }
        }

        for(int row_ = row-2;row_ >= 0;row_--){
            for(int col1 = 0;col1<col;col1++){
                for(int col2 = 0;col2<col;col2++){
                    int maxi = 0;
                    for(int i = -1;i<=1;i++){
                        for(int j = -1;j<=1;j++){
                            int val = (col1 == col2)? grid[row_][col1] : (grid[row_][col1] + grid[row_][col2]);
                            if(col1+i >= 0 && col1+1 < col && col2+j >= 0 && col2+j < col)
                                val+=dp[row_+1][col1+i][col2+j];
                            maxi = max(maxi,val);    
                        }
                    }
                    dp[row_][col1][col2] = maxi;
                }
            }
        }
        return dp[0][0][col-1];
    }
};
