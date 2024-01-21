#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      unordered_map<int,int> losses;
      for(auto match: matches){
        int losser = match[1];
        int winner = match[0];
        if(losses.find(losser) != losses.end()){
          losses[losser] += 1;
        }
        else{
          losses[losser] = 1;
        }
        if(losses.find(winner) == losses.end()){
          losses[winner] = 0;
        }
      }
      vector<int> notLose;
      vector<int> loseOne;
      for(auto it = losses.begin(); it != losses.end(); it ++){
        if(it ->second == 0){
          notLose.push_back(it->first);
        }
        if(it -> second == 1){
          loseOne.push_back(it->first);
        }
      }
      sort(notLose.begin(),notLose.end());
      sort(loseOne.begin(),loseOne.end());
      vector<vector<int>> ans = {notLose,loseOne};
      return ans;
    }
};