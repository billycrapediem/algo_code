#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i ++){
            for(int k = i + 1; k < nums.size() - 2;k ++){
                int left = k + 1, right = nums.size() - 1;
                while(left < right){
                    if(target > nums[i] + nums[k] + nums[left] + nums[right]){
                        left ++;
                    }
                    else if (target < nums[i] + nums[k] + nums[left] + nums[right]){
                        right --;
                    }
                    else{
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        ans.push_back(tmp);
                        while( left < right&&nums[left] == nums[left + 1] ){
                            left ++;
                        }
                        while(left < right && nums[right] == nums[right - 1] ){
                            right --;
                        }
                        left ++;

                    }
                }
                while(k  < nums.size() - 2 && nums[k] == nums[k + 1] ){
                    k ++;
                }
            }
            while(i < nums.size() - 3&& nums[i] == nums[i + 1] ){
                i ++;
            }
        }
        return ans;
    }
};

int main(){ 
    Solution x;
    vector<int> z = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> y = x.fourSum(z, 0);
    for(int i = 0; i < y.size(); i ++){
        for(int j = 0; j < 4; j ++){
            cout<<y[i][j]<<"  ";
        }
        cout<<endl;
    }

}