class Solution {
    struct Interval {
        long long start, end, weight;
        int id;
    };

    struct Result {
        long long weight;
        vector<int> indices;
    };

    vector<Interval> intervals_sorted;
    vector<vector<Result>> memo;
    int n;

    // Returns true if 'a' is strictly better than 'b'
    bool isBetter(const Result& a, const Result& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight; // We want the maximum weight
        }
        return a.indices < b.indices; // Tie-breaker: lexicographically smaller indices
    }

    Result solve(int i, int quota) {
        if (i == n || quota == 0) {
            return {0, {}};
        }
        if (memo[i][quota].weight != -1) {
            return memo[i][quota];
        }

        // Option 1: Skip current interval
        Result skip_res = solve(i + 1, quota);

        // Option 2: Pick current interval
        // Binary search for the first interval that starts strictly after intervals_sorted[i].end
        Interval target = {intervals_sorted[i].end + 1, 0, 0, 0};
        auto it = lower_bound(intervals_sorted.begin() + i + 1, intervals_sorted.end(), target, 
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });
        int next_idx = distance(intervals_sorted.begin(), it);

        Result next_res = solve(next_idx, quota - 1);
        vector<int> picked_indices = next_res.indices;
        picked_indices.push_back(intervals_sorted[i].id);
        sort(picked_indices.begin(), picked_indices.end());

        Result pick_res = {intervals_sorted[i].weight + next_res.weight, picked_indices};

        // Choose the best option
        return memo[i][quota] = (isBetter(pick_res, skip_res) ? pick_res : skip_res);
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        intervals_sorted.resize(n);
        for (int i = 0; i < n; ++i) {
            intervals_sorted[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by start time, then end time, then original ID
        sort(intervals_sorted.begin(), intervals_sorted.end(), [](const Interval& a, const Interval& b) {
            if (a.start != b.start) return a.start < b.start;
            if (a.end != b.end) return a.end < b.end;
            return a.id < b.id;
        });

        // Memoization table initialized with weight = -1
        memo.assign(n + 1, vector<Result>(5, {-1, {}}));

        Result best = solve(0, 4);
        return best.indices;
    }
};