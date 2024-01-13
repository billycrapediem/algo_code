#include<stack>
#include<string>

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i ++){
            if(ans.size() == 0|| abs(ans[ans.size() - 1]-s[i]) != 0){
                ans.push_back(s[i]);
            }
            else{
                ans.pop_back();
            }
        }
        return ans;
    }
};