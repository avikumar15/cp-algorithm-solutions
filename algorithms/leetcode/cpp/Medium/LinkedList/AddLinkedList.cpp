// https://leetcode.com/problems/add-two-numbers/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    
    int carry(ListNode* n1, ListNode* n2, ListNode*& fin, int cry) {
        
        if(n1==NULL && n2==NULL)
            return cry;
        
        if(n1==NULL) {
            fin = new ListNode((n2->val+cry)%10,fin);
            return carry(n1,n2->next,fin,(n2->val+cry)/10);
        }
        
        if(n2==NULL) {
            fin = new ListNode((n1->val+cry)%10,fin);
            return carry(n1->next,n2,fin,(n1->val+cry)/10);
        }
        
        fin = new ListNode((n1->val+cry+n2->val)%10,fin);
        
        return carry(n1->next,n2->next,fin,(n1->val+cry+n2->val)/10);
        
    }
    
    void reverse(ListNode* &head) {
        
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            
            next = current->next;
 
            current->next = prev;
 
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* fin = NULL;
        
        int val = carry(l1,l2,fin,0);
        
        if(val==1)
            fin = new ListNode(1,fin);
        
        reverse(fin);
        
        return fin;
    }
};