class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i>m-1 || j>n-1) return 1e9;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right=grid[i][j]+solve(m,n,i,j+1,grid,dp);
        int bottom=grid[i][j]+solve(m,n,i+1,j,grid,dp);
        return dp[i][j]=min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,grid,dp);
    }
};