#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> dp(target + 1, 0);
       dp[0] =1;
       for(int i = 1; i <= target; i ++){
            for(int num : nums){
                if(i - num >= 0){
                    dp[i] += dp[i - num];
                }
            }
       }
       return dp[target];
    }
};


int main(){ 
    Solution x;
    vector<int> y = {1,2,3};
    cout<<x.combinationSum4(y,4);

}