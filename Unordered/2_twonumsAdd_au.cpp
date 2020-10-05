#include<iostream>
using namespace std;

// 写在刷题后： 
// 这段代码基本是官解代码，看了官解代码之后还是收获颇多。
// 首先认识到了自己的菜鸡本质。其次学习到了一些语句的用法，化繁为简，代码没有那么冗繁复杂了。
// 其次看了官解之后我还是提交了三次代码才通过，所以自己在coding的过程中思考量还是太少。
// 特别是在迭代的过程中，脑子中没有这么个过程，导致犯了两个比较重要的错误，一是忘记了进位，二是忘记了两个链表的迭代。下次注意。


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        // 头指针和尾指针
        ListNode* head = nullptr; ListNode* tail = nullptr;
        // 可以直接判断结点是否为空
        int carry = 0;
        while(l1 || l2){
        // 根据两个链表是否为空来分别取值
            int n1 = l1? l1->val:0;
            int n2 = l2? l2->val:0;
            if(!head) {
                head = new ListNode((n1 + n2 + carry)%10);
                tail = head;
            }
            else{
                tail->next = new ListNode((n1 + n2 + carry)%10);
                tail = tail->next;
            }
            carry = (n1 + n2 + carry)/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry!=0) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        } 
        return head;
    }
};

