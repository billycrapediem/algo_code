#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;
        while(i < j){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                ans[k] = nums[j];
                j --;
            }
            else{
                ans[k] = nums[i];
                i ++;
            }
            k--;
        }
        return ans;
    }
};


int main(){ 

}