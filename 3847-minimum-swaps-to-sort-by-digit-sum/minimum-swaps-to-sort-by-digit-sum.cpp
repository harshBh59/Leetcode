
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int x : nums) {
            a.push_back({x, digitSum(x)});
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x.second != y.second)
                return x.second < y.second;
            return x.first < y.first;
        });

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[a[i].first] = i;
        }

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[nums[i]] == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
