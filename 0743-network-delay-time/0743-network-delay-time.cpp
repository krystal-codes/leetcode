class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> time(n + 1);
        for (int i = 1 ; i <= n ; i++) {
            time[i] = 1e9;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        time[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(dis + edgeWeight < time[adjNode]) {
                    time[adjNode] = dis + edgeWeight;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }
        int mx = INT_MIN;
        for (int x : time) {
            mx = max(mx, x);
        }
        if(mx == 1e9) return -1;
        else return mx;
    }
};