#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 分别记录距离n 和 n-1 的两个结点
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        if(!head->next) return nullptr;
        // n_1_node 是要被删除的结点
        ListNode* n_node = head; ListNode* n_1_node = head->next;
        int n_far = -1;  int n_1_far = -2;
        ListNode* p = head;
        while(p){
            n_far++;
            n_1_far++;

            if(n_far > n){
                n_node = n_node->next;
                n_far--;
            }
            if(n_1_far > (n-1)){
                n_1_node = n_1_node->next;
                n_1_node --;
            }
            
            p = p->next;
        }
        n_node->next = n_1_node->next;
        return p;
    }
};