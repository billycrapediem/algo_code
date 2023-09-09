
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1,false));
        dp[0][0] = true;
        for(int i = 1; i <=s1.size(); i ++){
            if(s1[i - 1] == s3[i - 1]) dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i <= s2.size(); i ++){
            if(s2[i - 1] == s3[i - 1]) dp[0][i] = dp[0][i - 1];
        }
        for(int i = 1; i <= s1.size(); i ++){
            for(int j = 1; j <= s2.size(); j ++){
                dp[i][j] = (( s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]) || ((s2[j - 1] == s3[i + j - 1])&& dp[i][j - 1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(){
    Solution x;
    string a = "ab";
    string b = "bc";
    string c = "babc";
    cout<<x.isInterleave(a,b,c);
}