#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 中序遍历二叉搜索树
// 将要插入的数放入所得到的数组中
// 然后构建新的二叉搜索树

// 看了下Leetcode官方的题解，感觉自己写的太垃圾了。。思路太复杂

class Solution {
public:
    vector<int> Tree;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        DFS(root);
        Tree.push_back(val);
        if(Tree.size()>1)sort(Tree.begin(),Tree.end(),cmp);
        return CreateNewTree(0,Tree.size()-1);
    }
    
    TreeNode* CreateNewTree(int low, int high){
        int mid;
        if((low+high)%2 == 0) mid = (low+high)/2;
        else mid = (low + high)/2 +1;
        if(high - low <=2){
             TreeNode* t = new TreeNode(Tree[mid]);
             if(low != mid) {
                TreeNode* s = new TreeNode(Tree[low]);
                t->left = s;
             }
             if(high != mid){
                TreeNode* s = new TreeNode(Tree[high]);
                t->right = s;
             }
            return t;
        }
        else{
            TreeNode* t = new TreeNode(Tree[mid]);
            t->left = CreateNewTree(low,mid-1);
            t->right = CreateNewTree(mid+1,high);
            return t;
       }
    }

    bool cmp(int a,int b){
        return a<b;
    }

    void DFS(TreeNode* root){
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

/*
Leetcode 官方题解：
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* pos = root;
        while (pos != nullptr) {
            if (val < pos->val) {
                if (pos->left == nullptr) {
                    pos->left = new TreeNode(val);
                    break;
                } else {
                    pos = pos->left;
                }
            } else {
                if (pos->right == nullptr) {
                    pos->right = new TreeNode(val);
                    break;
                } else {
                    pos = pos->right;
                }
            }
        }
        return root;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/solution/er-cha-sou-suo-shu-zhong-de-cha-ru-cao-zuo-by-le-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/