class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        for(int i = 0;i<n-2;i++){
            if(i > 0 && nums[i-1] == nums[i]) continue; // this line to skip the duplicate triplet
                int left = i+1;
                int right = n-1;
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right];
                    if(sum > 0) right--;
                    else if(sum < 0) left++;
                    else{
                        ans.push_back({nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left-1] == nums[left]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
        }
        return ans;
    }
};
