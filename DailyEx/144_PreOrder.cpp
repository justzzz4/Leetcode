#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 二叉树的前序遍历，采用一个栈保存根节点
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        vector<TreeNode*>tree;
        if(root){
            tree.push_back(root);
        }
        // 当栈不为空时
        while(tree.size()!=0){
            TreeNode* p = *(tree.end() -1);
            tree.pop_back();
            ans.push_back(p->val);
            if(p->right) tree.push_back(p->right);
            if(p->left) tree.push_back(p->left);
        }
    return ans;
    }
};