#include<deque>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        newQueue que;
        for(int i = 0; i < k; i ++){
          que.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(que.front());
        for(int i = k; i < nums.size(); i ++){
          que.pop(nums[i - k]);
          que.push(nums[i]);
          ans.push_back(que.front());
        }
        return ans; 
    }
private:
  class newQueue{
      public:
        deque<int> myqueue;
        void push(int x){
          
          while(!myqueue.empty() && x > myqueue.back()){
            cout<<myqueue.front()<<" "<<x<<endl;
            myqueue.pop_back();
          }
          myqueue.push_back(x);
        }
        void pop(int x){
          if(!myqueue.empty() && x == myqueue.front()){
            myqueue.pop_front();
          }
        }
        int front(){
          return myqueue.front();
        }
    };
};

int main(){
  Solution x;
  vector<int> z = {1,3,1,2,0,5};
  vector<int> y = x.maxSlidingWindow(z,3);
  for(int i = 0; i < y.size(); i ++){
    cout<<y[i]<<endl;
  }
}