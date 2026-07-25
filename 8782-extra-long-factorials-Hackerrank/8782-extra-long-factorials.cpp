#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
string prod_digit(char d1, char d2){
    if(d1=='1' || d2=='1') return string(1, (d1=='1')? d2: d1);
    int num1= d1-'0';
    int num2= d2-'0';
    return to_string(num1*num2);
}

string summ(string d1, string d2){
    int i = d1.size() - 1;
    int j = d2.size() - 1;
    int carry = 0;
    string ans = "";
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) { sum += d1[i] - '0'; i--; }
        if (j >= 0) { sum += d2[j] - '0'; j--; }
        ans = to_string(sum % 10) + ans;
        carry = sum / 10;
    }
    return ans;
}

string bigintMulti(int multiplier, string num2){
    string num1= to_string(multiplier);
    int n= num1.size();
    int m= num2.size();
    int cnt=0;
    vector<string> listing;
    
    for(int idx=n-1; idx>=0; idx--){
        string r_curr="";
        int k=0;
        while(k<cnt){
            k++;
            r_curr+='0';
        }
        char carry= '0';
        for(int j=m-1; j>=0; j--){
            string temp= prod_digit(num1[idx], num2[j]);
            string ongoing= summ(temp, string(1,carry));
            
            if(ongoing.size()==1){
                r_curr+=ongoing;
                carry= '0';
            }else{
                r_curr+= ongoing[1];
                carry= ongoing[0];
            }
        }
        if(carry != '0') r_curr += carry;
        
        reverse(r_curr.begin(), r_curr.end());
        listing.push_back(r_curr);
        
        cnt++; 
    }
    
    int z= listing.size();
    string ans= listing[0];
    for(int k=1; k<z; k++){ 
        ans= summ(ans, listing[k]);
    }
    return ans;
}

void extraLongFactorials(int n) {
    if(n<=1) cout<< n << endl;
    else {
        string curr="1";
        for(int i=2; i<= n; i++){
            curr= bigintMulti(i, curr);
        }
        cout<< curr<< endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna