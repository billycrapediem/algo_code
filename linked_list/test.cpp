#include<iostream>
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
int main(){
    Node* head = new Node(1);
    unordered_map<int, Node*> store;
    store[0] = head;
    Node* y = store[0];
    cout<<y->val;
}