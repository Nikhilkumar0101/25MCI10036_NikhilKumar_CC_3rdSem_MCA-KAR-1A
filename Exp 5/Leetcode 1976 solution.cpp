class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto road: roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> distance(n,LLONG_MAX);
        vector<int> pathCount(n,0);
        pq.push({0,0});
        distance[0]=0;
        pathCount[0]=1;

        long long MOD=1e9+7;

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            long long currTime=p.first;
            int currNode=p.second;

            for(auto adjacent: adj[currNode]){
                int adj_node=adjacent.first;
                int adj_time=adjacent.second;

                if(currTime+adj_time<distance[adj_node]){
                    distance[adj_node]=currTime+adj_time;
                    pq.push({currTime+adj_time,adj_node});
                    pathCount[adj_node]=pathCount[currNode];
                }
                else if(currTime+adj_time==distance[adj_node]){
                    pathCount[adj_node]=(pathCount[adj_node]+pathCount[currNode])%MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};