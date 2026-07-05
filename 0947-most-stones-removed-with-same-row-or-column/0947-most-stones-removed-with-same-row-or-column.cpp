class Solution {
public:
    int findup(vector<int>& parent, int num){
        if(num==parent[num]) return num;
        return parent[num]= findup(parent, parent[num]); //PaTH COMPRESSION
    }
    void unionbysize(vector<int>& size, vector<int>& parent, int num1, int num2){
        int u_id= findup(parent, num1);
        int v_id= findup(parent, num2);
        if(u_id==v_id) return;
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
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        vector<int> size(n, 1);
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for(int i= 0; i<n; i++) {
            for(int j= i+1; j<n; j++) {
                if(stones[i][0]== stones[j][0]||stones[i][1]== stones[j][1]){
                    unionbysize(size, parent, i, j);
                }
            }
        }
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) freq[findup(parent, i)];
        return (n-freq.size());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna