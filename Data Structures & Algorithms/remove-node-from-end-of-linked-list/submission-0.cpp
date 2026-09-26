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
        
        //count the number of nodes
        ListNode* cur = head;
        int count = 0;

        while(cur != NULL){
            count++;
            cur = cur->next;
        }

        count = count - n + 1;

        if(count == 1) return head->next;
        
        ListNode* prev = head;
        cur = head;
        int pos = 1;

        while(pos != count){
            prev = cur;
            cur = cur->next;
            pos++;
        }
        prev->next = cur->next;
        delete cur;
        return head;
    }
};
