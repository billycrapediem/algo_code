#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> store;
        for(int i = 0; i < groupSizes.size(); i ++){
            int s = groupSizes[i];
            if(! store.count(s) > 0){
                vector<int> tmp;
                tmp.push_back(i);
                store[s] = tmp;

            }
            else{
                store[s].push_back(i);
            }
            if(store[s].size() == s){
                    ans.push_back(store[s]);
                    store.erase(s);
                }
        }
        for(map<int,vector<int>>::iterator itr = store.begin(); itr != store.end(); itr++){
            ans.push_back(itr -> second);
        }
        return ans;
    }
};


int main(){
    Solution x;
    vector<int> y = {3,3,3,3,3,1,3};
    vector<vector<int>> z = x.groupThePeople(y);
    for(int i = 0; i < z.size(); i ++){
        for(int j = 0; j < z[i].size(); j ++){
            cout<<z[i][j]<<" ";
        }
        cout<<endl;
    }
 
}