#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
      vector<int> next = hasNext(needle);
      int index = -1;
      for(int i = 0; i < haystack.size(); i ++){
        while(index >= 0 && haystack[i] != needle[index + 1]){
          index = next[index];
        }
        if(needle[index + 1] == haystack[i]){
          index ++;
        }
        if(index == needle.size() - 1){
          return i - index;
        }
      }
      return -1;
    }
    vector<int> hasNext(string needle){
      vector<int> next(needle.size(),-1);
      int j = -1;
      for(int i = 1; i < needle.size(); i ++){
        while(j >=0 && needle[i] != needle[j + 1]){
          j = next[j];
        }
        if(needle[i] == needle[j + 1]){
          j ++;
        }
        next[i] = j;
      }
      return next;
    }
};

int main(){

}