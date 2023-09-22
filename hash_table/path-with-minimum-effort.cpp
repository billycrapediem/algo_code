#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<tuple>
#include<queue>


using namespace std;

class Solution {
public:

    bool in_bound(int x, int y,int h, int l){
        if(x >= l || x < 0) return false;
        if(y >= y || y < 0) return false;
        return true;
    }
    int hust(int x, int y, int h,int l){
        return l - x + h - y;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int h = heights.size(), l = heights[0].size();
        vector<vector<int>> move = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(h, vector<int>(l, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0,0,0);
        while(!minHeap.empty()){
            auto [effort,x,y] = minHeap.top();
            minHeap.pop();
            if(effort > dist[y][x]) continue;
            if(x == l - 1 && y == h - 1) return effort;
            for(int i = 0; i < move.size(); i ++){
                int xx = x + move[i][1], yy = y + move[i][0];
                if(in_bound(xx,yy,h,l)){
                    int new_effort = max(effort,abs(heights[y][x] - heights[yy][xx]));
                    if(new_effort < effort){
                        dist[y][x] = new_effort;
                        minHeap.emplace(new_effort,x,y);
                    }
                }
            }
        }
        
        return dist[h - 1][l - 1];
    }
};

int main(){ 
    Solution x;
    vector<vector<int>> map = {{1,2,2},{3,8,2},{5,3,5}};
    cout<<x.minimumEffortPath(map);

}