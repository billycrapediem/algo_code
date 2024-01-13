#include<stack>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int cnt;
        for(int i = 0; i < tokens.size(); i ++){
          if(tokens[i] == "+"||tokens[i] == "-"||tokens[i] == "*"||tokens[i] == "/"){
            int first = s.top();
            s.pop();
            int sec = s.top();
            s.pop();
            if(tokens[i] == "+"){
              s.push(first + sec);
            }
            else if(tokens[i] == "-"){
              s.push(sec - first);
            }
            else if(tokens[i] == "*"){
              s.push(first * sec);
            }
            else {
              s.push(sec / first);
            }
          }else{
            s.push(stoi(tokens[i]));
          }
        }
        return s.top();
    }
};