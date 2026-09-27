class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &pre: prerequisites){
            int a=pre[0];
            int b=pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        int cnt=0;

        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            cnt++;
            ans.push_back(currNode);

            for(int adj_node: adj[currNode]){
                indegree[adj_node]--;

                if(indegree[adj_node]==0) q.push(adj_node);
            }
        }
        if(cnt==numCourses) return ans;
        return {};
    }
};