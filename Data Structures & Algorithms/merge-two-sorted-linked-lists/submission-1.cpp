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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            } else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if(p1 != nullptr){
            cur->next = p1;
        }
        if(p2 != nullptr){
            cur->next = p2;
        }

        return head->next;
        
    }
};
