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
    int sumNumbers(TreeNode* root){
        if(!root) return 0;
        int rootVal = root->val; 
        int sum = 0;
        // 遍历整颗树，将数据存入数组中
        if(!root->left && !root->right) return rootVal;
        if(root->left) sum += addNumber(root->left,rootVal);
        if(root->right) sum += addNumber(root->right,rootVal);
        return sum;
    }
    int addNumber(TreeNode* t,int add){
        add = add * 10 + t->val;
        // 递归结束的条件
        if(!t->left && !t->right) return add;
        
        // 递归过程 
        int addleft = 0; int addright = 0;
        if(t->left) addleft = addNumber(t->left,add);
        if(t->right) addright = addNumber(t->right,add);
        return (addleft + addright);
    }
};