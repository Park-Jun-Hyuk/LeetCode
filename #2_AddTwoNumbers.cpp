#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    
    ListNode* restHead = new ListNode();
    ListNode* curNode = restHead;
    while(curNode != nullptr)
    {
        int l1Val = 0, l2Val = 0;
        
        if(nullptr != l1){
            l1Val = l1->val;
            l1 = l1->next;
        } 
        if(nullptr != l2) {
            l2Val = l2->val;
            l2= l2->next;
        }

        curNode->val += l1Val + l2Val;
        if(curNode->val >= 10)
        {
            curNode->next = new ListNode(curNode->val / 10);
            curNode->val = curNode->val %10;
        }
        else
        {
            if(!(nullptr == l1 && nullptr == l2))
                curNode->next = new ListNode();
        }
        
        curNode = curNode->next;
    }

    return restHead;
}


int main()
{
    ListNode* l1Head = new ListNode();
    ListNode* l1 = l1Head;

    l1->val = 2;
    l1->next = new ListNode();
    l1 = l1->next;

    l1->val = 4;
    l1->next = new ListNode();
    l1 = l1->next;

    l1->val = 3;


    ListNode* l2Head = new ListNode();
    ListNode* l2 = l2Head;

    l2->val = 5;
    l2->next = new ListNode();
    l2 = l2->next;

    l2->val = 6;
    l2->next = new ListNode();
    l2 = l2->next;

    l2->val = 4;

    addTwoNumbers(l1Head, l2Head);
}