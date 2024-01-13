#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '('|| s[i] == '[' || s[i] == '{'){
                if(s[i] == '('){
                    x.push(')');
                }
                if(s[i] == '['){
                    x.push(']');
                }
                if(s[i] == '{'){
                    x.push('}');
                }
            }
            else{
                if(!x.empty()&&s[i] == x.top()){
                    x.pop();
                }
                else{
                    return false;
                }
            }
        }
        return x.empty();
    }
};
