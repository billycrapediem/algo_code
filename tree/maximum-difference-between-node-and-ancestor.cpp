#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
#include<map>
#include "../template/Tree.h" 

using namespace std;

class Solution {
public:
    int maxDiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        difference(root, root->val, root->val);
        return maxDiff ;
    }
    void difference(TreeNode* root, int treMin, int treMax ){
        
        maxDiff = max(maxDiff,max(abs(root->val - treMin), abs(root->val - treMax)));
                
        treMin = min(treMin, root->val);
        treMax = max(treMax, root->val);
        if(root->left){
            difference(root->left, treMin, treMax);
        }
        if(root->right){
            difference(root->right, treMin, treMax);
        }
    }
};