#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int preAns = 100000;
        for(int i = 0; i < matrix[0].size(); i ++){
            dp[0][i] = matrix[0][i];
            preAns = min(preAns, dp[0][i]);
        }
        if(matrix.size() == 1){
            return preAns;
        }
        int ans = 10000000;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j ++){
                if(j == 0){
                    dp[i][j] = min(dp[i - 1][j],dp[i - 1][j + 1]) + matrix[i][j];
                }
                else if (j == matrix[0].size() - 1){
                    dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1]) + matrix[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i - 1][j - 1],dp[i - 1][j + 1])) + matrix[i][j];
                }
                if(i == matrix.size() - 1){
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};

