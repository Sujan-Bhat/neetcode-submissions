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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* cur = head;
        int count = 0;

        while(cur != nullptr){
            count++;
            cur = cur->next;
        }

        int idx = count - n;

        if(idx == 0) return head->next;

        cur = head;
        ListNode* prev = head;

        while(idx > 0){
            prev = cur;
            cur = cur->next;
            idx--;
        }
        if(cur->next){
            prev->next = cur->next;
        } else{
            prev->next = nullptr;
        }

        return head;
    }
};
