// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* t = head;
        ListNode* prev = NULL;
        int flag = 0;
        
        if(!t || !t->next)
            return head;
        
        ListNode* ans = t -> next;
        
        while(t && t->next) {
            ListNode* str = t -> next;
            t -> next = str -> next;
            str -> next = t;
            
            if(flag == 1) {
                prev -> next = str;
            }
            
            prev = t;
            t = t -> next;
            flag = 1;
        }
        
        return ans;
    }
};
