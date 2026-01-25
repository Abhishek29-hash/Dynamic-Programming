// class Solution {
//     int solve(int ind, int fee, int buy, vector<int>&prices, vector<vector<int>>&dp){
//         if(ind == prices.size()) return 0;

//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         if(buy){
//             return dp[ind][buy] = max((-prices[ind] + solve(ind+1,fee,0,prices,dp)), solve(ind+1,fee,1,prices,dp));
//         }
//         else{
//             return dp[ind][buy] = max((prices[ind] - fee + solve(ind+1,fee,1,prices,dp)), solve(ind+1,fee,0,prices,dp));
//         }
//     }
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();

//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solve(0,fee,1,prices,dp);
//     }
// };





// tabulation for space optimisation 

class Solution {
public:
    int maxProfit(vector<int>& values, int fee) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0; // base case
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                long profit;
                if (buy == 1) {
                    profit = max(-values[idx] + dp[idx + 1][0],
                                 dp[idx + 1][1]);
                } else {
                    profit =
                        max(values[idx] - fee + dp[idx + 1][1], dp[idx + 1][0]);
                }

                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
