class Solution {
public:
    int solve(int idx,vector<int>&nums,int n,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int pick=nums[idx]+solve(idx+2,nums,n,dp);
        int notPick=solve(idx+1,nums,n,dp);
        return dp[idx]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return solve(0,nums,n,dp);
    }
};