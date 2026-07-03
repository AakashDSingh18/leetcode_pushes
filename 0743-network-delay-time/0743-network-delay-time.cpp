class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> shortest(n, INT_MAX);
        q.push({0, k-1});
        shortest[k-1]= 0;
        while(!q.empty()){
            int curr= q.top().second;
            int tm= q.top().first;
            q.pop();
            for(int i=0; i<graph[curr].size(); i++){
                if(shortest[graph[curr][i].first] > tm+graph[curr][i].second){
                    shortest[graph[curr][i].first]= tm+graph[curr][i].second;
                    q.push({tm+graph[curr][i].second, graph[curr][i].first});
                }
            }
        }
        int maxi= INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, shortest[i]);
        }
        return (maxi==INT_MAX)? -1: maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna