class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = 4e18;
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0 ; i < roads.size(); i ++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> time(n, INF);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        time[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > time[node]) continue;
            for (auto it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;
                long long newDist = (dis + edgeWeight);
                if(newDist < time[adjNode]) {
                    time[adjNode] = dis + edgeWeight;
                    ways[adjNode] = ways[node];
                    pq.push({time[adjNode], adjNode});
                }
                else if(newDist == time[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};