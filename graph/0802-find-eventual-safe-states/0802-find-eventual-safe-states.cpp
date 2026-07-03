class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> outdegree(n, 0);
        queue<int> track;
        vector<vector<int>> rev_graph(n, vector<int>());
        for(int i=0; i<n; i++){
            outdegree[i]= graph[i].size();
            if(outdegree[i]==0) track.push(i);
            for(int j=0; j<graph[i].size(); j++){
                rev_graph[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        while(!track.empty()){
            int curr= track.front();
            ans.push_back(curr);
            track.pop();
            for(int i=0; i<rev_graph[curr].size(); i++){
                outdegree[rev_graph[curr][i]]--;
                if(outdegree[rev_graph[curr][i]]==0) track.push(rev_graph[curr][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna