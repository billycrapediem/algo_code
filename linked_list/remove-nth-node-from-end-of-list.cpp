#include "../template/LinkedList.h"

using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        for(int i = 0; i < n; i ++){
          end = end->next;
        }
        ListNode* cur = head;
        ListNode* pre = cur;
        while(end){
          pre = cur;
          cur = cur->next;
          end = end->next;
        }
        if(cur == head)
        {
            return cur ->next;
        }
        pre ->next = cur -> next;
        return head;
    }
};

