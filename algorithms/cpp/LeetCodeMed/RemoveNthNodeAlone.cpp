// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<bits/stdc++.h>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        
        for(int i=0; i<n; i++) {
            t1 = t1->next;
        }
        
        if(t1 == NULL) {
            t2 = t2 -> next;
            delete(head);
            return t2;
        }
        
        while(t1 && t1->next) {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        if(true) {
            ListNode* nxt = t2 -> next;
            if(nxt == NULL) {
                t2 = NULL;
            } else {
                t2 -> next = nxt->next;
            }
            delete(nxt);
        }
        
        return head;
    }
};