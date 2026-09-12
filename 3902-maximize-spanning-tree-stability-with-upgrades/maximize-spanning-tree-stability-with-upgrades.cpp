class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        parent[b] = a;
        return true;
    }

    bool check(int n, vector<vector<int>>& edges, int k, int x) {

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        int cnt = 0, used = 0;

        // Mandatory edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2], must = e[3];

            if (must) {
                if (w < x || !unite(u, v))
                    return false;
                cnt++;
            }
        }

        // Normal optional edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2], must = e[3];

            if (!must && w >= x && unite(u, v))
                cnt++;
        }

        // Upgraded optional edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2], must = e[3];

            if (!must && 2LL * w >= x && w < x && used < k) {
                if (unite(u, v)) {
                    cnt++;
                    used++;
                }
            }
        }

        return cnt == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo = 1, hi = 2e9, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};