class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>());
        vector<int> cheapest(n, INT_MAX);
        for(int i=0; i<flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int,int>> q;
        q.push({0, src});
        cheapest[src]= 0;
        k++;
        while(!q.empty() && k--){
            int temp= q.size();
            while(temp--){
                int curr= q.front().second;
                int pr= q.front().first;
                q.pop();
                int m= graph[curr].size();
                for(int i=0; i<m; i++){
                    if(cheapest[graph[curr][i].first] > pr+graph[curr][i].second){
                        cheapest[graph[curr][i].first]= pr+graph[curr][i].second;
                        q.push({pr+graph[curr][i].second, graph[curr][i].first});
                    }
                }
            }
        }
        return (cheapest[dst]==INT_MAX)? -1: cheapest[dst];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna