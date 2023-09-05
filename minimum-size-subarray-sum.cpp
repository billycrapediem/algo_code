#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, ans = INT_MAX, sum = 0;    
        for(int right = 0; right < nums.size(); right ++){
            sum += nums[right];
            while(sum >= target){
                ans = min(ans, right - left + 1);
                left ++;
                sum -= nums[left];
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};


int main(){ 

}