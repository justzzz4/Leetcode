#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> Tree;
    // vector<int> RootNode;
    bool isValidBST(TreeNode *root)
    {
        bool isValid = true;
        DFS(root);
        if (Tree.size() == 0)
            return true;
        else
        {
            for (int i = 0; i < Tree.size() - 1; i++)
            {
                if (Tree[i] >= Tree[i + 1])
                    isValid = false;
            }
        }
        /*
        for (int i = 0; i < RootNode.size(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < RootNode[i]; j++)
                {
                    if (Tree[j] > Tree[RootNode[i]])
                        isValid = false;
                }
            }
            else
            {
                for (int j = RootNode[i-1]; j < RootNode[i]; j++)
                {
                    if (Tree[j] < RootNode[i-1] || Tree[j] > RootNode[i])
                    {
                        isValid = false;
                    }
                }
            }
        }
        for(int i = RootNode[RootNode.size()-1] ; i < Tree.size();i++){
            if(Tree[i] < Tree[RootNode[RootNode.size()-1]]) isValid = false;
        }*/
        return isValid;
    }
    void DFS(TreeNode *root)
    {
        // 中序遍历
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;
        if (root->left != nullptr)
        {
            if (root->left->left == nullptr && root->left->right == nullptr)
                Tree.push_back(root->left->val);
            else
                DFS(root->left);
        }
        Tree.push_back(root->val);
        // int i = Tree.size() - 1;
        // RootNode.push_back(i);
        if (root->right != nullptr)
        {
            if (root->right->left == nullptr && root->right->right == nullptr)
                Tree.push_back(root->right->val);
            else
                DFS(root->right);
        }
    }
};

//