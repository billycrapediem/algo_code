#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string Vowels = "aeiou";
    bool halvesAreAlike(string s) {
        int mid = s.length() / 2;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string a = s.substr(0,mid), b = s.substr(mid);
        return countVowels(a) == countVowels(b);
    }
    int countVowels(string a){
      int cnt = 0;
      for(int i = 0; i < a.size(); i ++){
        for(int j = 0; j < Vowels.size(); j ++){
          if(a[i] == Vowels[j]){
            cnt ++;
            break;
          }
        }
      }
      return cnt;
    }
};

int main(){ 

}