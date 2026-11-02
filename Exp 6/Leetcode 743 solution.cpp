class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);

        for (auto& edge : times) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adjList[u].push_back({v, weight});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        set<pair<int, int>> st;
        st.insert({0, k});

        while (!st.empty()) {
            auto [currDist, node] = *st.begin();
            st.erase(st.begin());

            if (currDist > dist[node]) continue;
            for (auto [nextNode, weight] : adjList[node]) {
                if (currDist + weight < dist[nextNode]) {
                    dist[nextNode] = currDist + weight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }

        int maxTime = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};