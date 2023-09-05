#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int findMax(vector<int> ans){
    vector<int> dp(ans.size() + 1, -1);
    dp[0] = 0;
    dp[1] = ans[0];
    dp[2] = ans[1];
    for(int i = 2; i <= ans.size(); i ++){
        int x, y, z;
        x = dp[i - 1];
        y = dp[i - 2] + ans[i - 1];
        z = dp[i - 3] + ans[i - 1] + ans[i - 2];
        dp[i] = max(x,y);
        dp[i] = max(dp[i], z);
    }
    return dp[ans.size()];
}
int main(){
    vector<int> z = {1,2,2,1,2,1,2,5,5};
    cout<<findMax(z)<<endl;
}