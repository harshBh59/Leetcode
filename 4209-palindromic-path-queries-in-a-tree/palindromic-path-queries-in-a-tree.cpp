class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n), pref(n);
        int timer = 0;

        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<int> st = {0};

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            tin[u] = timer++;
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int u : order) {
            up[0][u] = (u == 0 ? 0 : parent[u]);
            pref[u] = (u == 0 ? 0 : pref[parent[u]]) ^ (1 << (s[u] - 'a'));
        }

        for (int j = 1; j < LOG; j++)
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];

        for (int u = 0; u < n; u++)
            tout[u] = tin[u];

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            tout[parent[u]] = max(tout[parent[u]], tout[u]);
        }

        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto get = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int d = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (d & (1 << j)) u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }
            return up[0][u];
        };

        auto pathMask = [&](int u) {
            return pref[u] ^ get(tin[u]);
        };

        vector<bool> ans;

        for (auto &q : queries) {
            string type, c;
            int u, v;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c[0] - 'a'));

                if (delta) {
                    add(tin[u], delta);
                    if (tout[u] + 1 < n)
                        add(tout[u] + 1, delta);
                }

                s[u] = c[0];
            } else {
                ss >> v;
                int w = lca(u, v);
                int mask = pathMask(u) ^ pathMask(v) ^ (1 << (s[w] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};