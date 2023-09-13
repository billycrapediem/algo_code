#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        vector<long long> hash_map(26,0);
        for(int i = 0; i < s.size(); i ++){
            int tmp = s[i] - 'a';
            hash_map[tmp] ++;
        }
        int ans = 0;
        sort(hash_map.begin(),hash_map.end(),greater<int>());
        for(int i = 0; i < 25; i ++){
            int j = i + 1;
            while( hash_map[i] == hash_map[j] && hash_map[i] != 0){
                hash_map[j] --;
                j ++;
                ans ++;
            }
        }
        return ans;
    }
};


int main(){ 
    Solution x;
    cout<<x.minDeletions();
}