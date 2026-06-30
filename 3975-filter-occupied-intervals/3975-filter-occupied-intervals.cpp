class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        int n = occupiedIntervals.size();
        for (int i = 0; i < n; i++) {
            int start = (freeStart - 1 >= 0) ? freeStart - 1 : freeStart;
            if (occupiedIntervals[i][0] < freeStart && freeStart <= occupiedIntervals[i][1]) {
                if (occupiedIntervals[i][1] <= freeEnd)
                    ans.push_back({occupiedIntervals[i][0], start});
                else {
                    ans.push_back({occupiedIntervals[i][0], start});
                    ans.push_back({freeEnd + 1, occupiedIntervals[i][1]});
                }
            } else if (occupiedIntervals[i][0] <= freeEnd && freeEnd < occupiedIntervals[i][1]) {
                if (occupiedIntervals[i][0] >= freeStart)
                    ans.push_back({freeEnd + 1, occupiedIntervals[i][1]});
            } else if (occupiedIntervals[i][0] >= freeStart && occupiedIntervals[i][1] <= freeEnd) {
                continue;
            }else {
                ans.push_back(occupiedIntervals[i]);
            }
        }
        sort(ans.begin(), ans.end());
        vector<vector<int>> temp;
        if (ans.size() == 0) return temp;
        temp.push_back(ans[0]);
        for (int i = 1; i < ans.size(); i++) {
            int m = temp.size() - 1;
            if (ans[i][0] > temp[m][1] + 1)
                temp.push_back(ans[i]);
            else
                temp[m][1] =max(temp[m][1], ans[i][1]);
        }

        return temp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna