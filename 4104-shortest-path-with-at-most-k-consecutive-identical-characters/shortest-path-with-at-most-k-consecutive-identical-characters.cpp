class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX / 2;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        using P = tuple<long long, int, int, char>;
        priority_queue<P, vector<P>, greater<P>> pq;

        int cnt = 1;
        dist[0][cnt] = 0;
        pq.push({0, 0, cnt, labels[0]});

        while (!pq.empty()) {
            auto [cost, u, cnt, last] = pq.top();
            pq.pop();

            if (u == n - 1)
                return cost;

            for (auto [v, w] : adj[u]) {
                int newCnt = (labels[v] == last) ? cnt + 1 : 1;

                if (newCnt > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt, labels[v]});
                }
            }
        }

        return -1;
    }
};