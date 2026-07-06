class Solution {
public:
    int findup(vector<int>& parent, int num){
        if(num==parent[num]) return num;
        return parent[num]= findup(parent, parent[num]); //PaTH COMPRESSION
    }
    void unionbysize(vector<int>& size, vector<int>& parent, int num1, int num2){
        int u_id= findup(parent, num1);
        int v_id= findup(parent, num2);
        if(size[u_id] < size[v_id]){
            parent[u_id]= v_id;
            size[v_id]+= size[u_id];
        }else if(size[u_id] > size[v_id]){
            parent[v_id]= u_id;
            size[u_id]+= size[v_id];
        }else{
            parent[v_id]= u_id;
            size[u_id]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m= connections.size();
        if (m < n-1) return -1;
        vector<int> size(n, 1);
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i=0; i<m; i++){
            unionbysize(size, parent, connections[i][0], connections[i][1]);
        }
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) freq[findup(parent, i)]++;
        return freq.size()-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna