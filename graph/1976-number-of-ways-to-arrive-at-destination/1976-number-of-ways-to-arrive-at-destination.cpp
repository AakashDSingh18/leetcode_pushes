class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, long long>>> graph(n);
        for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]}); 
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            long long tm = q.top().first;
            int curr = q.top().second;
            q.pop();
            if (tm > dist[curr]) continue;
            for(int i = 0; i < graph[curr].size(); i++) {
                int nextNode = graph[curr][i].first;
                long long weight = graph[curr][i].second;
                if (dist[nextNode] > tm + weight) {
                    dist[nextNode] = tm + weight;
                    ways[nextNode] = ways[curr];
                    q.push({dist[nextNode], nextNode});
                }
                else if (dist[nextNode] == tm + weight) {
                    ways[nextNode] = (ways[nextNode] + ways[curr]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna