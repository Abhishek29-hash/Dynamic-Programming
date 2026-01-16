// this code give the tle tc = 0(n^2)
// class Solution {
//     int solve(int i, int j, vector<vector<int>>&tri, vector<vector<int>>&dp){

//         if(i == tri.size()-1) return tri[i][j];

//         if(dp[i][j] != -1) return dp[i][j];
//         int down = tri[i][j] + solve(i+1,j,tri,dp);
//         int diago = tri[i][j] + solve(i+1,j+1,tri,dp);

//         return dp[i][j] = min(down, diago);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int row = triangle.size();
//         vector<vector<int>> dp(row,vector<int>(row,-1));

//         // {0,0} starting index of the recursion 
//         return solve(0,0,triangle,dp);
//     }
// }; 

// try to solve in 0(n);


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangles) {
        // int n = triangles.size();
        // vector<vector<int>> dp(n, vector<int>(n,0));

        // for(int i = 0;i<n;i++) dp[n-1][i] = triangles[n-1][i];

        // for(int i = n-2;i>=0;i--){
        //     for(int j = i;j>=0;j--){
        //         int down = triangles[i][j] + dp[i+1][j];
        //         int diago = triangles[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(down,diago);
        //     }
        // }
        // return dp[0][0];


        // try to write the code in 0(n) space complexity

        int n = triangles.size();
        vector<int> dp(n,0);

        for(int i = 0;i<n;i++) dp[i] = triangles[n-1][i];

        for(int i = n-2;i>=0;i--){
            vector<int> temp(triangles[i].size(),0);
            for(int j = i; j>= 0;j--){
                int down = triangles[i][j] + dp[j];
                int diag = triangles[i][j] + dp[j+1];
                temp[j] = min(down,diag);
            }
            dp = temp;
        }
        return dp[0];
    }
};
