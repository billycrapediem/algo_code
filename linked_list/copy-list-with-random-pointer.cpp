#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, Node*> store;
        Node* list_node = head;
        Node* ans = new Node(head->val);
        store[head] = ans;
        Node* cur = ans;
        while(list_node){
            Node* random_Node = list_node->random;
            if(!random_Node) cur->random = NULL;
            else{
                // hashtable does not contain the element
                if(store.find(random_Node) == store.end()){
                    store[random_Node] = new Node(random_Node->val);
                }
                cur->random = store[random_Node];
            }
            Node* next_node = list_node->next;
            if(!next_node) break;
            if(store.find(next_node) == store.end()){
                store[next_node] = new Node(next_node->val);
            }
            cur->next = store[next_node];
            list_node = list_node->next;
            cur = cur->next;
        }
        return ans;
    }
};

int main(){ 

}