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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k= operators.size();
        vector<int> dist= {1, 0, -1, 0, 1};
        vector<int> size(k, 1);
        vector<int> parent(k);
        vector<int> ans;
        vector<vector<pair<int, int>>> matr(n, vector<pair<int, int>>(m, {0,-1}));
        iota(parent.begin(), parent.end(), 0);
        int curr= 0;
        for(int i=0; i<k; i++){
            if (matr[operators[i][0]][operators[i][1]].first){
                ans.push_back(curr);
                continue;
            }
            matr[operators[i][0]][operators[i][1]]= {1, i};
            curr++;
            for(int j=0; j<4; j++){
                int nr= operators[i][0]+ dist[j];
                int nc= operators[i][1]+ dist[j+1];
                if(nr<n && nc<m && nr>=0 && nc>=0 && matr[nr][nc].first==1){
                    int root1= findup(parent, matr[nr][nc].second);
                    int root2= findup(parent, i);
                    if(root1!=root2) {
                        unionbysize(size, parent, root1, root2);
                        curr--;
                    }
                }
            }
            // unordered_map<int, int> freq;
            // for(int j=0; j<=i; j++){
            //     freq[findup(parent, j)]++;
            // }
            // curr= freq.size();
            ans.push_back(curr);
        }
        return ans;
        
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna