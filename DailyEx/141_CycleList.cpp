#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 题目中没说不重复果然测试样例是有重复的。。
// 因此这个思路就要改进一下

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 如果链表中只有一个结点
        if(!head || !head->next) return false;
        unordered_set<int> urset;
        ListNode* p = head->next;
        urset.insert(head->val);
        // 如果链表有环，那么这个while永远也不会退出
        while(p){
            // 这个status表示是否进入循环
            int beginCycle = 0;
            int status = 0;
            // 遍历过程 1、检测结点是否在set中，如果不在将结点值存入set中 2、如果在那么久返回true
            auto it = urset.find(p->val);
            if(it != urset.end()) {
                // 如果找到相同的值那么就要判断是不是成环
                if( !p->next && urset.find(p->next->val)!= urset.end()) status = 1; 
                if( p->val == beginCycle && status) return true;
            }
            else{
                urset.insert(p->val);
                if(!p &&urset.find(p->next->val)!= urset.end()) beginCycle = p->next->val;
            }
            p = p->next;
        }
        // 反之如果无环，就可以退出
        return false;
    }
};