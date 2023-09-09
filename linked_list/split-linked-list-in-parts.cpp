#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int len = 0;
        for(ListNode* i = head; i != nullptr; i = i->next){
            len ++;
        }
        int size = len / k, occur = len % k;
        ListNode* cur = head
        for(int i = 0; i < k; i ++){
            ans[i] = cur;
            int j = 1;
            if(i < occur){
                j = 0;
            }
            while( cur && j < size){
                j++;
                cur = cur -> next;
            }
            if(cur){
                ListNode* next_node = cur -> next;
                cur -> next = nullptr;
                cur = next_node;
            }
        }
        return ans;
    }
};


int main(){ 

}






