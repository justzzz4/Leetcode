#include<iostream>
#include<vector>
using namespace std;

// 当连接好上一层的next指针后，下一层next指针的连接可以借助上一层的next指针来实现。

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        // 根节点next设置为空
        root->next = nullptr;
        // 进入递归
        findNext(root);
    }
    
    void findNext(Node* root){
        if(!root) return;
        Node* n = root;
        if(!n->left) return;
        Node* nextRoot = n->left;
        Node* nRight = nullptr;
        while(n){
            
            // 设置不同父节点之间的子节点的next关系
            if(nRight) nRight->next = n->left; 
            
            // 设置同一父节点的子节点关系
            n->left->next = n->right; 
            nRight = n->right;
            n = n->next;  
        }
        nRight->next = nullptr;
        findNext(nextRoot);
    }
};
// 