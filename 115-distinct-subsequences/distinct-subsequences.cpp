class Solution {
public:
    int n,m;
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int match = 0;
        int notMatch =0;
        if(s[i] == t[j]){
            match = solve(i-1, j, s, t, dp) + solve(i-1, j-1, s, t, dp);
        }
        else{
            notMatch = solve(i-1, j, s, t, dp);
        }
        return dp[i][j] = match + notMatch;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};