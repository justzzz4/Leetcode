#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 控制结构采用while循环
// 设置一个标识位，表示是前结点还是后结点
// 对于前结点保存，对于后结点再执行交换操作

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head; ListNode* newHead; ListNode* s;
        
        if(head->next) newHead = head->next;
        else newHead = head;
        
        int isSwap = 0;
        while(p){
            if(!isSwap){
                ListNode* s = p;
                isSwap = 1;
                p = p->next;                
            }
            else{
                if(p->next) s->next = p->next;
                else s->next = nullptr;
                p->next = s;
                isSwap = 0;
                p = p->next->next;
            }
        }
        return newHead;
    }
};