class Solution {
public:
    int call(vector<int>& nums,int idx,int l,vector<int>&dp){
        int n=nums.size();
        if(idx<l) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+call(nums,idx-2,l,dp);
        int notPick=call(nums,idx-1,l,dp);
        return dp[idx]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int case1=call(nums,n-2,0,dp1);
        int case2=call(nums,n-1,1,dp2);
        return max(case1,case2);
    }
};