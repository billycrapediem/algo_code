#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int i = 0, j = 0, k = nums1.size() - 1, l = nums2.size() - 1;
        bool flag = (k + l ) % 2 == 0;
        while(i + j <= k + l){
            if( i + j + 1 == k + l && flag){
                double low = (nums1[i], nums2[j]);
                double high = (nums1[k], nums2[l]);
                ans = (low + high) /2;
                return ans;
            }
            else if(i + j == k + l && ! flag){
                ans =  max(nums1[i], nums2[j]);
                return ans;
            }
            if(nums1[i] < nums2[j]){
                i ++;
            }
            else{j ++;}
            if(nums1[k]  > nums2[l] && k > 0){
                k --;
            }
            else if(l >0){
                l --;
            }
        }
        return 0;
    }
};


int main(){ 
    Solution x;
    vector<int> y  = {1,3};
    vector<int> z = {2};
    cout<<x.findMedianSortedArrays(y,z);

}