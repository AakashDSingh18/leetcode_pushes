class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m= connections.size();
        if (m < n-1) return -1;
        vector<int> rank(n, 0);
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i=0; i<m; i++){
            int u_id = parent[connections[i][0]];
            int v_id = parent[connections[i][1]];
            if(u_id == v_id) continue;
            if(rank[u_id] < rank[v_id]){
                for(int j=0; j<n; j++){
                    if(parent[j]==u_id) parent[j]= v_id;
                }
            }else if(rank[u_id] > rank[v_id]){
                for(int j=0; j<n; j++){
                    if(parent[j]==v_id) parent[j]= u_id;
                }
            }else{
                rank[u_id]++;
                for(int j=0; j<n; j++){
                    if(parent[j]==v_id) parent[j]= u_id;
                }
            }
        }
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[parent[i]]++;
        }
        return freq.size()-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna