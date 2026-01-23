class Solution {
    int solve(int ind, int k, vector<int>&nums, vector<vector<int>>&dp){

        if(ind == 0){
            if(k == 0 && nums[ind] == 0) return 2;
            if(k == 0 || nums[ind] == k) return 1;
            return 0;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int not_take = solve(ind-1,k,nums,dp);
        int take = 0;
        if(nums[ind] <= k) take = solve(ind-1,k-nums[ind],nums,dp);
        return dp[ind][k] = (take + not_take);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum-target<0 || (total_sum-target)%2) return 0;
        int target_sum = (total_sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(target_sum+1,-1));
        return solve(n-1,target_sum,nums,dp);
    }
};
