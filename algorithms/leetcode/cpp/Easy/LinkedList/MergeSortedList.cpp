// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* ans = NULL;
        
        ListNode* copy1 = l1;
        ListNode* copy2 = l2;
        
        while(l1&&l2) {
            if(l1->val<l2->val) {
                if(ans==NULL)
                    ans = l1;
                else {
                    ans->next = l1;
                    ans = ans->next;
                }
                l1 = l1->next;
            } else {
                if(ans == NULL)
                    ans = l2;
                else {
                    ans->next = l2;
                    ans = ans->next;
                }
                l2 = l2->next;
            }               
        }
        
        if(!l1)
            ans->next = l2;
        if(!l2)
            ans->next = l1;
        
        if(copy1->val<copy2->val)
            ans = copy1;
        else
            ans = copy2;
        
        return ans;
    }
};
