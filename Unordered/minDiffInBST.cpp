#include <iostream>
#include <algorithm>
using namespace std;

// 第一个步将所给的树重构大根堆
// 第二步利用递归将最小值返回

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        // 大根堆的建立过程
        for(int i = 0 ; i<6;i++)
        bigRootHeap(root);
        // 遍历返回最小值
        return minDiff(root);
    }

    int minDiff(TreeNode *root){
        if(root->left == nullptr && root->right == nullptr) return INT32_MAX;
        if(root->left == nullptr) return abs(root->val-root->right->val);
        if(root->right == nullptr) return abs(root->val - root->left->val);
        int a = INT32_MAX;
        int b = INT32_MAX;
        if(root->left!=nullptr) a = abs(root->val - root->left->val);
        if(root->right!=nullptr) b = abs(root->val - root->right->val);
        int diff = (a < b) ? a : b;
        int a_ = INT32_MAX;
        int b_ = INT32_MAX;
        if (root->left != nullptr)  a_ = minDiff(root->left);
        if (root->right != nullptr)  b_ = minDiff(root->right); 
        // 没有比较diff 和 b_ 的最小值
        
        return min(diff,min(a_,b_));
    }
    void bigRootHeap(TreeNode *root)
    {
        TreeNode *t = root;
        shift(t);
        if (t->left != nullptr) shift(t->left);
        if (t->right != nullptr) shift(t->right);
    }
    void shift(TreeNode *node)
    {   if(node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr)
            return;
        if (node->left == nullptr){
            if(node->val < node->right->val) {
                // swap
                int temp = node->val;
                node->val = node->right->val;
                node->right->val = temp;
                return;
            }
        }if (node->right == nullptr){
            if(node->val < node->left->val) {
                // swap
                int temp = node->val;
                node->val = node->left->val;
                node->left->val = temp;
                return;
            }
        }
        if ((node->val < node->left->val || node->val < node->right->val) && node->left != nullptr && node->right != nullptr)
        {
            if (node->val < node->right->val)
            {
                if (node->left->val < node->right->val)
                {
                    int var = node->val;
                    node->val = node->right->val;
                    node->right->val = var;
                }
                else
                {
                    int var = node->val;
                    node->val = node->left->val;
                    node->left->val = var;
                }
            }
            else
            {
                //如果根节点值小于左结点的值但大于等于右节点的值，交换根节点与左节点的值
                int var = node->val;
                node->val = node->left->val;
                node->left->val = var;
            }
        }
    }
};

int main()
{
    int a = 2;
    int diff = 3;
    int b = 4;
    int c = (diff < a) ? diff : ((a < b) ? a : b);
    cout << c;
    return 0;
}