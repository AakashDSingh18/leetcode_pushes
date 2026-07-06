class Solution {
public:
    int findup(vector<int>& parent, int num){
        if(num== parent[num]) return num;
        return parent[num]= findup(parent, parent[num]);
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
            parent[u_id]= v_id;
            size[v_id]+= size[u_id];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> dist= {1, 0, -1, 0, 1};
        vector<int> size(n*n, 1);
        vector<int> parent(n*n);
        iota(parent.begin(), parent.end(), 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    for(int k=0; k<4; k++){
                        int nr= i+ dist[k];
                        int nc= j+ dist[k+1];
                        if(nr<n && nc<n && nr>=0 && nc>=0 && grid[nr][nc]){
                            int root1= findup(parent, (nr*n)+nc);
                            int root2= findup(parent, (i*n)+j);
                            if(root1!=root2) {
                                unionbysize(size, parent, root1, root2);
                            }
                        }
                    }
                }
            }
        }
        int ans= INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    int sum=0;
                    unordered_map<int, int> check;
                    for(int k=0; k<4; k++){
                        int nr= i+ dist[k];
                        int nc= j+ dist[k+1];
                        if(nr<n && nc<n && nr>=0 && nc>=0 && grid[nr][nc]){
                            int root1= findup(parent, (nr*n)+nc);
                            int curr= size[root1];
                            if(check.find(root1)!=check.end()) continue;
                            sum+= curr;
                            check[root1]++;
                        }
                    }
                    ans= max(ans, sum+1);
                }
            }
        }
        return (ans<0)? n*n: ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna