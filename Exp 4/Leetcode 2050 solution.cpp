class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (const auto& rel : relations) {
            int prev = rel[0], next = rel[1];
            graph[prev].push_back(next);
            inDegree[next]++;
        }
        
        queue<int> q;
        vector<int> maxTime(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i - 1];
            }
        }
        
        int totalMinTime = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            totalMinTime = max(totalMinTime, maxTime[curr]);
            
            for (int neighbor : graph[curr]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[curr] + time[neighbor - 1]);
                
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return totalMinTime;
    }
};