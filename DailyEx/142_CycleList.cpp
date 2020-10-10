#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    //可以不存放int，直接存放ListNode* 指针值 
    ListNode* detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        while (head)
        {
            if (set.count(head))
            {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
