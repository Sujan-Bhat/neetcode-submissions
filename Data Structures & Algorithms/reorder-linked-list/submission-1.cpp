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
    void reorderList(ListNode* head) {

        if(head->next == nullptr || head->next->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp1 = new ListNode();

        while(slow != nullptr){
            temp1 = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp1;
        }

        ListNode* cur1 = head;
        ListNode* cur2 = prev;
        ListNode* temp2 = new ListNode();

        while(cur1 != nullptr && cur2 != nullptr){
            temp1 = cur1->next;
            temp2 = cur2->next;
            cur1->next = cur2;
            cur2->next = temp1;

            cur1 = temp1;
            cur2 = temp2;
        }

        if(cur1) cur1->next = nullptr;

        return;

    }
};
