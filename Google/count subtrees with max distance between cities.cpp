#leetcode 1617

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]-1].push_back(e[1]-1);
            graph[e[1]-1].push_back(e[0]-1);
        }
        vector<int> ans(n - 1, 0);
        for (int state = 1; state < (1 << n); state++) {
            int d = maxDistance(state, graph, n);
            if (d > 0) ans[d - 1] += 1;
        }
        return ans;
    }
    
    int maxDistance(int state, vector<vector<int>>& graph, int n) {
        int anyNode = 0, cntCity = 0;
        for (int i = 0; i < n; i++) if ((state >> i) & 1) {
            anyNode = i;
            cntCity += 1;
        }
        auto [farthestNode, _, visitedSize] = bfs(anyNode, state, graph, n);
        if (visitedSize < cntCity) return 0; // Can't visit all nodes of the tree -> Invalid tree
        auto [_ig1, dist, _ig2] = bfs(farthestNode, state, graph, n);
        return dist;
    }
    
    tuple<int, int, int> bfs(int src, int state, vector<vector<int>>& graph, int n) {
        unordered_set<int> visited{src};
        queue<pair<int,int>> q;
        q.push({src, 0});
        int farthestNode = -1, farthestDist = 0;
        while(!q.empty()){
            auto [u, d] = q.front(); q.pop();
            farthestNode = u, farthestDist = d;
            for (int v : graph[u]){
                if (visited.find(v) == visited.end() && (state >> v) & 1){
                    q.push({v, d + 1});
                    visited.insert(v);
                }
            }
        }
        return make_tuple(farthestNode, farthestDist, visited.size());
    }
};
