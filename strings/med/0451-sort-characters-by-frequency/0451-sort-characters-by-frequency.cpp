class Solution {
private:
    static bool comparator(pair<int,char> ele1, pair<int,char> ele2){
        if(ele1.first>ele2.first) return true;
        if(ele1.first<ele2.first) return false;
        return ele1.second<ele2.second;
    }
public:
    string frequencySort(string s) {
        pair<int, char> ans_hash[65];
        string ans;
        ////Set array with pairs having value 0 for all letters we need
        for(int i=0; i<62; i++){
            if(i>51) ans_hash[i]={0,i-52+'0'};
            else if(i>25) ans_hash[i]={0,i-26+'a'};
            else ans_hash[i]= {0,i+'A'};
        }

        ////Traversing and incrementing the value of the corresponding letter in the araay in its pair
        for(auto i :s){
            if(int(i)>96) ans_hash[i+26-'a'].first++;
            else if(int(i)<58) ans_hash[i+52-'0'].first++;
            else ans_hash[i-'A'].first++;
        }
        sort(ans_hash,ans_hash+62,comparator);
        int i=0;
        while(i<62){
            if(ans_hash[i].first==0){
                i++;
                continue;
            }
            ans+=ans_hash[i].second;
            ans_hash[i].first--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna