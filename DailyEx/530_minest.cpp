#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> tree;
    // 中序遍历树，将结点值存入数组
    void DFS(TreeNode* root){
        if(root)
        {
            if(root->left) DFS(root->left);
            tree.push_back(root->val);
            if(root->right) DFS(root->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        DFS(root);
        int min = INT32_MAX;
        for(int i =0; i < tree.size()-1;i++){
            min = ((tree[i+1] - tree[i])< min)? (tree[i+1] - tree[i]): min;
        }
        return min;
    }
    
};