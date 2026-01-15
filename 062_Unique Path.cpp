// recurrence solution so it give the tle

// tc = 0(2^m*n)
// sc = (m-1*n-1) // due to the stack i.e it store the path 


// class Solution {
//     int solve(int row,int col){
//         if(!row && !col) return 1;
//         if(row < 0 || col < 0) return 0;

//         int up = solve(row-1,col);
//         int left = solve(row,col-1);

//         return up+left;
//     }
// public:
//     int uniquePaths(int m, int n) {

//         // m-1 , n-1.  1 indexing are followed here 

//         return solve(m-1,n-1);
//     }
// };

// optimisation using dp memoization

// time complexity = 0(n*m);

// space complexity = 0(n*m) dp + 0((n-1) + (m-1)) recursive stack space 

// class Solution {
//     int solve(int row,int col, vector<vector<int>>&dp){
//         if(!row && !col){
//             return dp[row][col] = 1;
//         }
//         if(row < 0 || col < 0) return 0;

//         if(dp[row][col] != -1) return dp[row][col];

//         int up = solve(row-1,col,dp);
//         int left = solve(row,col-1,dp);

//         return dp[row][col] = (up+left);
//     }
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,dp);
//     }
// };


// tabulation sc = 0(n*m);   this is for space optimisation

// most prefarable moslution

class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int row = 0;row < m;row++){
            for(int col = 0;col<n;col++){
                if(!row && !col){
                    dp[row][col] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                if(row > 0) up = dp[row-1][col];
                if(col > 0) left = dp[row][col-1];
                dp[row][col] = (up+left);
            }
        }
        return dp[m-1][n-1];
    }
};


// space optimisation  time complexity = 0(m)


// class Solution {
//     public:
//     int uniquePaths(int m, int n) {
//         vector<int> prev_row(m,0);

//         for(int row = 0;row<m;row++){
//             vector<int> temp(n,0);
//             for(int col = 0;col<n;col++){
//                 if(!row && !col){
//                     temp[row] = 1;
//                     continue;
//                 }
//                 int up = 0;
//                 int left = 0;
//                 if(row > 0) up = prev_row[col];
//                 if(col > 0) left = temp[col-1];
//                 temp[col] = up + left;
//             }
//             prev_row = temp;
//         }
//         return prev_row[n-1];
//     }
// };
