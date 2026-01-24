// time limit exceed 46/47
// memoization

// class Solution {
//     int solve(int len1, int len2, string s1, string s2,vector<vector<int>>&dp){
//         if(len1<0 || len2<0) return 0;

//         if(dp[len1][len2] != -1) return dp[len1][len2];
//         if(s1[len1] == s2[len2]) return dp[len1][len2] = 1 + solve(len1-1,len2-1,s1,s2,dp);
//         return dp[len1][len2] = max(solve(len1-1,len2,s1,s2,dp),solve(len1,len2-1,s1,s2,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int len1 = text1.size();
//         int len2 = text2.size();
//         vector<vector<int>>dp(len1,vector<int>(len2,-1));
//         return solve(len1-1, len2-1, text1, text2,dp);
//     }
// };



// here i do. 1 right shifting 

// for thus we have indresse the row and col of the dp by 1 and pass n instead of n-1
// class Solution {
//     int solve(int len1, int len2, string s1, string s2,vector<vector<int>>&dp){
//         if(len1 == 0 || len2 == 0) return 0;

//         if(dp[len1][len2] != -1) return dp[len1][len2];

//         if(s1[len1-1] == s2[len2-1]) return dp[len1][len2] = 1 + solve(len1-1,len2-1,s1,s2,dp);
//         return dp[len1][len2] = max(solve(len1-1,len2,s1,s2,dp),solve(len1,len2-1,s1,s2,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int len1 = text1.size();
//         int len2 = text2.size();
//         vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
//         return solve(len1, len2, text1, text2,dp);
//     }
// };

// tabulation 
// in  tabulation the extra recursive stack space will be eliminated

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));

        // base case here 1 row and the col are involved in the base case
        // beacuse it take care of answer if the length of any one string will be 0;

        for(int i = 0;i<=l1;i++) dp[i][0] = 0;
        for(int j = 0;j<=l2;j++) dp[0][j] = 0;

        
        for(int i = 1;i<=l1;i++){
            for(int j = 1;j<=l2;j++){
                // we compare i-1 instead of i because here we campare the first element of the string 
                // so we do this but i will store it on second row and second col 
                //because first row and col are are use to store 0 as a anser if the length of 
                // any one be 0 then answer will be 0;
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    }
};
