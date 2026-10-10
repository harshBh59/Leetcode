class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<int> d(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, d[i]);
            sum += d[i];
        }

        if (sum <= k) return 0;

        int l = 0, r = mx;

        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for (int x : d) {
                if (x > mid) need += x - mid;
            }

            if (need <= k) r = mid;
            else l = mid + 1;
        }

        int level = l;
        long long used = 0, ans = 0;

        for (int x : d) {
            int y = min(x, level);
            used += x - y;
            ans += 1LL * y * y;
        }

        long long rem = k - used;

        for (int x : d) {
            if (rem == 0) break;

            if (x >= level && x > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                rem--;
            }
        }

        return ans;
    }
};