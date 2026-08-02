class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<double> prob(n);
        for (int i = 0 ; i < n ; i ++) {
            prob[i] = 0;
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1, start_node});
        prob[start_node] = 1;
        while(!pq.empty()) {
            double pro = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(pro < prob[node]) continue;
            for (auto it : adj[node]) {
                double edgeProb = it.second;
                int adjNode = it.first;
                if(pro * edgeProb > prob[adjNode]) {
                    prob[adjNode] = pro * edgeProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return (prob[end_node] == 1) ? 0 : prob[end_node] ;
    }
};