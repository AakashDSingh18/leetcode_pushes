class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        int n= prerequisites.size();
        for(int i=0; i<n; i++){
            indegree[prerequisites[i][1]]++;
        }
        vector<vector<int>> edge(numCourses, vector<int>());
        for(int i=0; i<n; i++){
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> track;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                track.push(i);
                ans.push_back(i);
            }
        }
        while(!track.empty()){
            int curr= track.front();
            track.pop();
            for(int i=0; i<edge[curr].size(); i++){
                indegree[edge[curr][i]]--;
                if(indegree[edge[curr][i]]==0){
                    track.push(edge[curr][i]);
                    ans.push_back(edge[curr][i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        vector<int> empty;
        return (ans.size()!=numCourses)? empty: ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna