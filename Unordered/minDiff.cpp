#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> vals;
    static bool cmp(int a,int b){
        return a>b;
    }
    int minDiffInBST(TreeNode* root) {
        // 中序遍历树
        dfs(root);
        sort(vals.begin(),vals.end(),cmp);
        int minDiff = INT32_MAX;
        for(int i = 0; i < vals.size()-1;i++){
            if((vals[i] - vals[i+1]) < minDiff){
                minDiff = vals[i] - vals[i+1];
            }
        }
        return minDiff;
    }
    void dfs(TreeNode* root){
        // 中序递归
        if(root == nullptr) return;
        vals.push_back(root->val);
        if(root->left != nullptr) dfs(root->left);
        if(root->right != nullptr) dfs(root->right);
    }
};