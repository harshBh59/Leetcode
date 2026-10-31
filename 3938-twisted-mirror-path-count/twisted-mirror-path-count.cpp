class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );

        // dir: 0 = entered from left (moving right)
        //      1 = entered from above (moving down)
        function<int(int, int, int)> resolve =
            [&](int i, int j, int dir) -> int {

            if (i >= m || j >= n) return -1;

            if (memo[i][j][dir] != -2)
                return memo[i][j][dir];

            // Reflect: right -> down, down -> right
            int ni = i + (dir == 0);
            int nj = j + (dir == 1);

            if (ni >= m || nj >= n)
                return memo[i][j][dir] = -1;

            if (grid[ni][nj] == 0)
                return memo[i][j][dir] = ni * n + nj;

            return memo[i][j][dir] =
                resolve(ni, nj, 1 - dir);
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0 || grid[i][j] == 1)
                    continue;

                long long ways = dp[i][j];

                // Attempt to move right
                if (j + 1 < n) {
                    int dest;

                    if (grid[i][j + 1] == 0)
                        dest = i * n + j + 1;
                    else
                        dest = resolve(i, j + 1, 0);

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }

                // Attempt to move down
                if (i + 1 < m) {
                    int dest;

                    if (grid[i + 1][j] == 0)
                        dest = (i + 1) * n + j;
                    else
                        dest = resolve(i + 1, j, 1);

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;
                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};