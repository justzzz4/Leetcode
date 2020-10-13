#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代: 0、1作为一个循环
// 当为1时，不仅要交换结点，还要将上个循环末尾的结点next改为新循环头结点

class Solution {
public:
    vector<ListNode*> list;
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* newHead;
        if(head->next) newHead = head->next;
        else newHead = head;

        ListNode* h = head; ListNode* l = nullptr; ListNode* last = nullptr;
        int swap = 0;
        while(h){
            if(!swap){
                l = h;
                swap = 1;
                h = h->next;
            }
            else{
                // swap过程
                l->next = h->next;
                h->next = l;

                swap = 0;
                // 将上一过程的last结点next设置为头结点
                if(last) last->next = h; 

                last = l;
                h = h->next->next;
            }
        }
        return newHead;
    }
};