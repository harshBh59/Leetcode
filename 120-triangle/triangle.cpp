class Solution {
public:
    int call(vector<vector<int>>& triangle,int m,int i,int j, vector<vector<int>>&dp){
        if(i==m-1) return triangle[i][j];
        
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int ch1=triangle[i][j]+ call(triangle,m,i+1,j,dp);
        int ch2=triangle[i][j]+call(triangle,m,i+1,j+1,dp);
        return dp[i][j]=min(ch1,ch2);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        return call(triangle,m,0,0,dp);
    }
};