#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(i == 0 && j == 0){
                    continue;
                }
                else{
                    int x = 0, y = 0;
                    if(i > 0) x = dp[i - 1][j];
                    if(j > 0) y = dp[i][j - 1];
                    dp[i][j] = x + y;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


int main(){ 
    Solution x;
    cout<<x.uniquePaths(3,7);
    return 0;

}