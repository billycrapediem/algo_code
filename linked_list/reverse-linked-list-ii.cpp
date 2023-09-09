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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dum_ptr = new ListNode(0,head);
        ListNode* ahead = dum_ptr;
        ListNode* left_node = head;
        ListNode* right_node = head;
        int l = 1, r = 1;
        // find the edge of each node
        while(r < right){
            if(l < left){
                ahead = ahead->next;
                left_node = left_node->next;
                l++;
            }

            right_node = right_node -> next;
            r++;
        }
        ListNode* behind = right_node -> next;
        //swap the node in the range
        ahead->next = right_node;
        reverse(left_node,right_node);
        left_node->next = behind;
        return dum_ptr->next;
    }
    ListNode* reverse(ListNode* head, ListNode* tail){
        cout<<head -> val<<endl;
        if( head ==  tail) return head;
        ListNode* new_head = reverse(head->next, tail);
        new_head->next = head;
        return head;
    }
};


int main(){ 

}