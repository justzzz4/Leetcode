/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *s1 = l1->next;
        ListNode *s2 = l2->next;
        int add = 0;
        ListNode *root = new ListNode(l1->val + l2->val);
        if (root->val >= 10)
        {
            root->val = root->val % 10;
            add = 1;
        }
        ListNode *p = root;
        ListNode *s;
        while (s1 != nullptr || s2 != nullptr)
        {
            // 如果第一个为空
            if (s1 == nullptr)
            {
                s = new ListNode();
                if(s2 != nullptr)
                s->val = 0 + s2->val + add;
                add = 0;
                if (s->val >= 10)
                {
                    s->val = s->val % 10;
                    add = 1;
                }
                p->next = s;
                p = p->next;
                if(s2 != nullptr)
                s2 = s2->next;
            }
            else if (s2 == nullptr)
            {
                s = new ListNode();
                if(s1 != nullptr)
                s->val = 0 + s1->val + add;
                add = 0;
                if (s->val >= 10)
                {
                    s->val = s->val % 10;
                    add = 1;
                }
                p->next = s;
                p = p->next;
                if(s1 != nullptr)
                s1 = s1->next;
            }
            else
            {
                s = new ListNode();
                s->val = s1->val + s2->val + add;
                add = 0;
                if (s->val >= 10)
                {
                    s->val = s->val % 10;
                    add = 1;
                }
                p->next = s;
                p = p->next;
                if(s1 != nullptr)
                s1 = s1->next;
                if(s2 != nullptr)
                s2 = s2->next;
            }
        }
         if (add == 1)
        {
            s = new ListNode();
            s->val = 1;
            p->next = s;
            p = p->next;
        }
        return root;
    }
};