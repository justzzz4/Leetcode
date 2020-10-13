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

// 将链表中的每个结点存入了Vector数组中
// 然后将数组结点交换，最后连接返回

class Solution {
public:
    vector<ListNode*> list;
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        while(head){
            list.push_back(head);
            head = head->next;
        }
        
        int i = 0;
        for(i = 0; i < list.size() -1;i+=2){
            ListNode* temp = list[i];
            list[i] = list[i+1];
            list[i+1] = temp; 
            list[i]->next = list[i+1];
            list[i+1]->next = nullptr;
            if(i+3 < list.size())
            {
                list[i+1]->next = list[i+3];
            }
        }
        if(i == list.size()-1){
            list[i-1]->next = list[i];
            list[i] ->next = nullptr;
        }
        
        return list[0];
    }
};